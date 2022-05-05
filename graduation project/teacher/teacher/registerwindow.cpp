#include "registerwindow.h"
#include "ui_registerwindow.h"
#include "loginwindow.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QUrlQuery>

#if 1
QString RegisterWindow::sdkAppId = "crawlerw"; //初始化平台用户名
QString RegisterWindow::sdkAppKey = "2a2572315bb01cb9e40474649c6c07f0"; //平台对应账户的接口
int RegisterWindow::count = 60; //计数器的时间
#endif

RegisterWindow::RegisterWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RegisterWindow)
    ,msgBox(QMessageBox::Information, "温馨提示", "")
  ,icon_window(":/shangluo.png")
  ,icon_msgBox(":/message.jpg")
{
    ui->setupUi(this);
    //界面美化
    this->setFixedSize(this->width(),this->height());
    this->setWindowIcon(icon_window);
    QLineEdit *edits[5];
    edits[0] = ui->userlineEdit;
    edits[1] = ui->passwordlineEdit;
    edits[2] = ui->confirmpasswordlineEdit;
    edits[3] = ui->telephonelineEdit;
    edits[4] = ui->codelineEdit;
    for(int i = 0; i < 5; i++)
    {
        edits[i]->setStyleSheet("font: 25 14pt '微软雅黑 Light';" //字体
                                "color: rgb(31,31,31);"  //字体颜色
                                "padding-left:20px;"       //内边距-字体缩进
                                "background-color: rgb(255, 255, 255);" //背景颜色
                                "border:2px solid rgb(0, 170, 255);border-radius:15px;");//边框粗细-颜色-圆角设置
    }

    QPushButton *buttons[3];
    buttons[0] = ui->yesButton;
    buttons[1] = ui->returnButton;
    buttons[2] = ui->codeButton;
    for(int i = 0; i < 3; i++)
    {
        buttons[i]->setStyleSheet("QPushButton{color: rgb(255,255,255);background-color: rgb(0, 170, 255);"
                                            "border: none;border-radius:15px;}"
                                            "QPushButton:hover{background-color: rgb(22,218,208);}"//hover
                                            "QPushButton:pressed{background-color: rgb(17,171,164);}");//pressed
    }

    //设置消息盒子图标
    msgBox.setWindowIcon(icon_msgBox);
    msgBox.setStyleSheet("background-image: url(:/background.jpg);");

    //初始化验证码
    code = "";

    //初始化电话检查列表
    telephonelist << "134" << "135" << "136" << "137" << "138" << "139" << "147" << "148"
                  << "150" << "151" << "152" << "157" << "158" << "159" << "172" << "178"
                  << "182" << "183" << "184" << "187" << "188" << "198";  //移动
    telephonelist << "130" << "131" << "132" << "145" << "146" << "155" << "156" << "166"
                  << "171" << "175" << "176" << "185" << "186"; //联通
    telephonelist << "133" << "149" << "153" << "170" << "173" << "174" << "177"
                  << "180" << "181" << "189" << "199"; //电信

    //将计时器的信号和对应的槽函数连接
    timer = new QTimer;
    connect(timer, &QTimer::timeout, this, &RegisterWindow::calcount);
}

RegisterWindow::~RegisterWindow()
{
    delete ui;
}

void RegisterWindow::on_yesButton_clicked()
{
    //判断输入是否合法
    if(ui->userlineEdit->text() == "" || ui->passwordlineEdit->text() == "")
    {
        msgBox.setWindowTitle("注册提示");
        msgBox.setText("请输入合理的用户名和密码！");
        msgBox.exec();
        return;
    }

    //检查该用户名是否已经被使用
    QSqlQuery query("select * from userdata;");
    while(query.next())
    {
        if(query.value("user") == ui->userlineEdit->text())
        {
            msgBox.setWindowTitle("注册提示");
            msgBox.setText("该用户名已经被使用！");
            msgBox.exec();
            return;
        }
    }

    //判断两次密码是否一致
    if(ui->passwordlineEdit->text() != ui->confirmpasswordlineEdit->text())
    {
        msgBox.setWindowTitle("注册提示");
        msgBox.setText("两次密码输入不一致，请重新输入！");
        msgBox.exec();
        return;
    }

    //判断验证码是否正确
    if(ui->codelineEdit->text() == "" || ui->codelineEdit->text() != code)
    {
        msgBox.setWindowTitle("注册提示");
        msgBox.setText("验证码输入不正确，请重新输入！");
        msgBox.exec();
        return;
    }

    //将控件上的数据插入到表中
    QString tmpsql = QString("insert into userdata(user, password, telephone) values('%1', '%2', '%3');")
                            .arg(ui->userlineEdit->text())
                            .arg(ui->passwordlineEdit->text())
                            .arg(ui->telephonelineEdit->text());
    if(!query.exec(tmpsql))
    {
        msgBox.setWindowTitle("注册提示");
        msgBox.setText("注册失败！");
        msgBox.exec();
        return;
    }
    else
    {
        //准备要设置的字段
        QString str = "";
        tmpsql = QString("select * from tablename;");
        query.exec(tmpsql);
        while(query.next())
        {
            str += query.value("number").toString() + " = 0, ";
        }
        int len = str.length();
        str = str.remove(len - 2, 1);

        //对已有主题的标志位进行设置
        tmpsql = QString("update userdata set where user == '%1' and password == '%2';")
                         .arg(ui->userlineEdit->text())
                         .arg(ui->passwordlineEdit->text())
                         .insert(20, str);
        if(!query.exec(tmpsql))
        {
            msgBox.setWindowTitle("注册提示");
            msgBox.setText("标志位设置失败！");
        }

        timer->stop();
        ui->codeButton->setText("发送验证码");
        msgBox.setWindowTitle("注册提示");
        msgBox.setText("注册成功！");
        msgBox.exec();
    }
    ui->userlineEdit->clear();
    ui->passwordlineEdit->clear();
    ui->confirmpasswordlineEdit->clear();
    ui->codelineEdit->clear();
    ui->telephonelineEdit->clear();
    ui->codeButton->setEnabled(true);
    count = 60;
}

void RegisterWindow::on_returnButton_clicked()
{
    LoginWindow* lw = new LoginWindow;
    lw->show();
    this->close();
}

void RegisterWindow::on_passwordButton_clicked(bool checked)
{
    if(checked)
    {
        ui->passwordlineEdit->setEchoMode(QLineEdit::Password);
    }
    else
    {
        ui->passwordlineEdit->setEchoMode(QLineEdit::Normal);
    }
}
void RegisterWindow::on_confirmpasswordButton_clicked(bool checked)
{
    if(checked)
    {
        ui->confirmpasswordlineEdit->setEchoMode(QLineEdit::Password);
    }
    else
    {
        ui->confirmpasswordlineEdit->setEchoMode(QLineEdit::Normal);
    }
}

//------------------------------云信使平台点对点发送信息--------------------------------
void RegisterWindow::singleMessage(QString mobile, QString content)
{
    // 移动平台  http://sms.sms.cn/
    /*
     *  http://api.sms.cn/sms/?ac=send
        &uid=qq21497936&pwd=接口密码[获取密码]
        &template=100006&mobile=填写要发送的手机号
        &content={"code":"value"}
    */
    QString baseUrl = QString("http://api.sms.cn/sms/");
    QUrl url;
    url.setUrl(baseUrl);
    QUrlQuery urlQuery;
    urlQuery.addQueryItem("ac", "send");
    // 笔者平台账户
    urlQuery.addQueryItem("uid", sdkAppId);
    // 笔者平台账户接口密码
    urlQuery.addQueryItem("pwd", sdkAppKey);
    urlQuery.addQueryItem("template", "557972");
    urlQuery.addQueryItem("mobile", mobile);
    urlQuery.addQueryItem("content", QString("{\"code\":\"%1\"}").arg(content));
    url.setQuery(urlQuery);
    manager.get(QNetworkRequest(url));
}

//-------------------------------发送验证码--------------------------
void RegisterWindow::on_codeButton_clicked()
{
    //检查号码合法性
    if(ui->telephonelineEdit->text().length() != 11)
    {
        msgBox.setWindowTitle("注册提示");
        msgBox.setText("请输入合法的手机号！");
        msgBox.exec();
        return;
    }
    QString phone = ui->telephonelineEdit->text();
    QString tmpphone = phone.remove(3, 8); //获取电话号码前3位，方便检查合法性(简单的合法检查)

    //检查手机号码的有效性
    int i = 0;
    for(i = 0; i < telephonelist.length() && telephonelist[i] != tmpphone; i++)
    {
        ;
    }
    if(i == telephonelist.length())
    {
        msgBox.setWindowTitle("注册提示");
        msgBox.setText("请输入合法的手机号！");
        msgBox.exec();
        return;
    }

    //检查当前号码是否已经使用过
    QSqlQuery query("select telephone from userdata;");
    while(query.next())
    {
        if(query.value(0).toString() == ui->telephonelineEdit->text())
        {
            msgBox.setWindowTitle("注册提示");
            msgBox.setText("当前手机号已被注册！");
            msgBox.exec();
            return;
        }
    }

    //产生验证码
    srand((unsigned int)(QTime::currentTime()).msecsSinceStartOfDay());
    code = "";
    for(int i = 0; i < 4; i++)
    {
        code += QString::number(rand()%10);
    }
    //ui->codelineEdit->setText(code);
    //qDebug() << "code = " << code;

    singleMessage(ui->telephonelineEdit->text(), code); //发送点对点短信

    //将发送验证码控件设置为不能点击，并限时1分钟后点击-----------------未完成
    ui->codeButton->setEnabled(false);
    timer->start(1000);
}
//-------------------------计时器时间------------------------------------
void RegisterWindow::calcount()
{
    if(count == 0)
    {
        timer->stop();
        ui->codeButton->setEnabled(true);
        ui->codeButton->setText("发送验证码");
        count = 60;
        return;
    }
    ui->codeButton->setText(QString("请等待:%1S").arg(QString::number(count--)));
}
