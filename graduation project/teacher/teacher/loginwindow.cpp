#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "setwindow.h"
#include "registerwindow.h"
#include "modifywindow.h"
#include "votepage.h"
#include <QSqlQuery>
#include <QLineEdit>
#include <QFile>
LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWindow)
    ,msgBox(QMessageBox::Information, "温馨提示", "")
    ,icon_window(":/shangluo.png")
    ,icon_msgBox(":/message.jpg")
{
    ui->setupUi(this);

    //登陆界面控件美化
    this->setFixedSize(this->width(),this->height());
    this->setWindowIcon(icon_window);
    this->setStyleSheet("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(251,102,102, 200), stop:1 rgba(20,196,188, 210));");
    ui->logolabel->setStyleSheet("image: url(:/shangluo.png)");
    QLineEdit* edits[2];
    edits[0] = ui->userlineEdit;
    edits[1] = ui->passwordlineEdit;
    for(int i = 0; i < 2; i++)
    {
        edits[i]->setStyleSheet("font: 25 14pt '微软雅黑 Light';" //字体
                                            "color: rgb(31,31,31);"  //字体颜色
                                            "padding-left:20px;"       //内边距-字体缩进
                                            "background-color: rgb(255, 255, 255);" //背景颜色
                                            "border:2px solid rgb(20,196,188);border-radius:15px;");//边框粗细-颜色-圆角设置
    }
    ui->label_4->setStyleSheet("border-radius:15px;");//边框粗细-颜色-圆角设置
    ui->groupBox->setStyleSheet("background-color: rgb(255, 255, 255);" //背景颜色
                                 "border-radius:15px;");  //边框粗细-颜色-圆角设置
    QPushButton* buttons[4];
    buttons[0] = ui->voteButton;
    buttons[1] = ui->registerButton;
    buttons[2] = ui->modifyButton;
    buttons[3] = ui->setButton;
    for(int i = 0; i < 4; i++)
    {
        buttons[i]->setStyleSheet("QPushButton{font: 25 14pt '微软雅黑 Light';color: rgb(255,255,255);background-color: rgb(20,196,188);"
                                  "border: none;border-radius:15px;}"
                                  "QPushButton:hover{background-color: rgb(22,218,208);}"//hover
                                  "QPushButton:pressed{background-color: rgb(17,171,164);}");//pressed
    }

    //设置消息盒子图标
    msgBox.setWindowIcon(icon_msgBox);
    msgBox.setStyleSheet("background-image: url(:/background.jpg);");

    //根据类型连接数据库，并将数据库转成类对象
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("votedata.db");
    //db.setDatabaseName("D:\\database\\votedata.db");
    if(!db.open())
    {
        msgBox.setWindowTitle("数据库提示");
        msgBox.setText("创建数据库失败！");
        msgBox.exec();
    }

    //创建主题表(只需要一次)
    QSqlQuery query;
    QString tmpsql = QString("create table if not exists tablename(id integer primary key autoincrement, number text, themename text);");
    if(!query.exec(tmpsql))
    {
        msgBox.setWindowTitle("数据库提示");
        msgBox.setText("初始化主题表失败！");
        msgBox.exec();
    }

    //创建存放用户信息的表
    tmpsql = QString("create table if not exists userdata(id integer primary key autoincrement, user text, password text, telephone text);");
    if(!query.exec(tmpsql))
    {
        msgBox.setWindowTitle("温馨提示");
        msgBox.setText("用户信息表创建失败！");
        msgBox.exec();
    }
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

//-------------------------登陆（进入投票）---------------------------
void LoginWindow::on_voteButton_clicked()
{
    //判断输入是否合法
    if(ui->userlineEdit->text() == "" || ui->passwordlineEdit->text() == "")
    {
        msgBox.setWindowTitle("登陆提示");
        msgBox.setText("请合理输入用户名和密码！");
        msgBox.exec();
        return;
    }
    //判断用户名是否存在或者正确
    QSqlQuery query("select * from userdata;");
    while(query.next())
    {
        if(query.value("user").toString() == ui->userlineEdit->text() && query.value("password").toString() == ui->passwordlineEdit->text())
        {
            //投票页面
            VotePage *vp = new VotePage;
            connect(this, &LoginWindow::send_userdata, vp, &VotePage::receive_userdata);
            emit send_userdata(ui->userlineEdit->text(), ui->passwordlineEdit->text());
            vp->show();
            this->close();
            return;
        }
    }
    msgBox.setWindowTitle("登陆提示");
    msgBox.setText("用户名或密码错误！");
    msgBox.exec();
}


//-------------------------进入设置---------------------------
void LoginWindow::on_setButton_clicked()
{
    //设置页面
    SetWindow *sw = new SetWindow;
    sw->show();
    this->close();
}


//-------------------------用户注册---------------------------
void LoginWindow::on_registerButton_clicked()
{
    RegisterWindow *rw = new RegisterWindow;
    rw->show();
    this->close();
}

//-------------------------修改密码---------------------------
void LoginWindow::on_modifyButton_clicked()
{
    ModifyWindow *mw = new ModifyWindow;
    mw->show();
    this->close();
}


//---------------------------登陆时长按显示密码或者隐藏密码-----------------------------
void LoginWindow::on_passwordButton_clicked(bool checked)
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
