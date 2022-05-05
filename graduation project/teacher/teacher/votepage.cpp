#include "votepage.h"
#include "ui_votepage.h"
#include "loginwindow.h"
#include <QRadioButton>
#include <QSqlQuery>
#include <QVBoxLayout>
#include <QGroupBox>
#include "resultwindow.h"
#include <QComboBox>
#include <QCheckBox>
#include <QTextBrowser>
VotePage::VotePage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VotePage)
    ,msgBox(QMessageBox::Information, "温馨提示", "")
  ,icon_window(":/shangluo.png")
  ,icon_msgBox(":/message.jpg")
{
    ui->setupUi(this);
    //界面美化
    this->setFixedSize(this->width(),this->height());
    ui->submitButton->setStyleSheet("QPushButton{background-color: rgb(255, 255, 255);border: none;border-radius:15px;}"
                                    "QPushButton:hover{background-color: rgb(22,218,208);}"//hover
                                    "QPushButton:pressed{background-color: rgb(17,171,164);}");//pressed
    ui->returnButton->setStyleSheet("QPushButton{background-color: rgb(255, 255, 255);border: none;border-radius:15px;}"
                                    "QPushButton:hover{background-color: rgb(22,218,208);}"//hover
                                    "QPushButton:pressed{background-color: rgb(17,171,164);}");//pressed
    ui->lookButton->setStyleSheet("QPushButton{background-color: rgb(255, 255, 255);border: none;border-radius:15px;}"
                                    "QPushButton:hover{background-color: rgb(22,218,208);}"//hover
                                    "QPushButton:pressed{background-color: rgb(17,171,164);}");//pressed
    //设置登陆界面
    this->setFixedSize(this->width(),this->height());
    this->setWindowIcon(icon_window);

    //设置消息盒子图标
    msgBox.setWindowIcon(icon_msgBox);
    msgBox.setStyleSheet("background-image: url(:/background.jpg);");

    //将已有主题表显示在控件上
    //设置提示
    QSqlQuery query(QString("select * from tablename;"));
    while(query.next())
    {
        ui->displaylistWidget->addItem(query.value("themename").toString());
    }
}

VotePage::~VotePage()
{
    delete ui;
}

//-------------------------------------双击显示主题-------------------------------------
void VotePage::on_displaylistWidget_itemDoubleClicked(QListWidgetItem *item)
{
    if(tmpthemename != item->text())
    {
        bool isanswer = false; //记录是否已经作答
        //判断当前主题是否可以投票
        QSqlQuery tmpquery("select * from tablename;");
        while(tmpquery.next()) //获取主题对应的表编号
        {
            if(tmpquery.value("themename").toString() == item->text())
            {
                tmptable = tmpquery.value("number").toString();
                tmpthemename = item->text(); //当前主题名，切换主题时判断是否切换了主题，来进行跟新
                break;
            }
        }
        QString tmpsql = QString("select * from userdata;");
        tmpquery.exec(tmpsql);
        while(tmpquery.next())
        {
            if(tmpquery.value("user").toString() == user &&  tmpquery.value("password").toString() == password && tmpquery.value(tmptable).toString() == "1")
            {
                msgBox.setWindowTitle("投票提示");
                msgBox.setText("该主题你已完成作答，无法再次进行做答提交，如想再次作答，请联系管理员！");
                msgBox.exec();
                ui->submitButton->setEnabled(false);
                isanswer = true; //已经作答
            }
        }

        isopen = false; //默认当前主题中没有问题

        //创建一个文本显示框，将问题显示在上面
        QTextBrowser* textbrowser = new QTextBrowser(this);
        textbrowser->setGeometry(220, 50, 981, 731);

        //双击列表控件对应列表项目，获取表名
        QSqlQuery query(QString("select * from '%1'").arg(tmptable));

        //创建一个页面盒子,栈已在头文件中创好
        QComboBox *pageComboBox = new QComboBox;
        stackedWidget = new QStackedWidget;
        while(query.next()) //每次检索表中的一行
        {
            if(!isanswer)
            {
                //主题中有问题
                isopen = true;
            }

            QGroupBox *groupBox = new QGroupBox;
            //设置题目
            QTextBrowser* text = new QTextBrowser;
            text->setText(query.value("question").toString());

            //设置选项->第一步：从表中对应的行中，先将8个选项的内容存放在临时数组中
            QString choices[8]; //存储8个选项
            int count = 0; //选项的个数
            for(int i = 0; i < 8; i++)
            {
                if("" != (choices[count] = query.value(QString("option%0").arg(i+1)).toString()) || !query.value(QString("imagine%1").arg(i+1)).toByteArray().isEmpty())
                {
                    count++;
                }
            }
            //设置选项->第二步：根据多选还是单选创建相应的选项
            if(0 == query.value("state").toInt())
            {
                //单选
                QHBoxLayout* hlayout[8]; //创建垂直布局
                for(int i = 0; i < count; i++) //创建count个单选
                {

                    //创建垂直布局
                    hlayout[i] = new QHBoxLayout;

                    //准备选项内容
                    QTextBrowser *content = new QTextBrowser;
                    content->setText(choices[i]);

                    //准备单选图标
                    QRadioButton* radio = new QRadioButton;

                    //准备选项图片
                    QLabel *img = new QLabel;
                    img->setFixedWidth(180);
                    img->setFixedHeight(100);
                    QByteArray arry = query.value(QString("imagine"+QString::number(i+1))).toByteArray();
                    if(!arry.isEmpty())
                    {
                        QPixmap outimg;
                        outimg.loadFromData(arry);
                        QPixmap fitpixmap = outimg.scaled(img->width(), img->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);  // 饱满填充
                        img->setPixmap(fitpixmap); //设置图片
                    }
                    //将图片，图标，内容放入布局
                    hlayout[i]->addWidget(radio);
                    if(!arry.isEmpty())
                    {
                        hlayout[i]->addWidget(img);
                    }
                    hlayout[i]->addWidget(content);
                }

                //将题目和选项添加到盒子中
                QVBoxLayout *singlebox = new QVBoxLayout;
                singlebox->addWidget(text);
                for(int i = 0; i < count; i++)
                {
                    singlebox->addLayout(hlayout[i]);
                }
                groupBox->setLayout(singlebox);
            }
            else
            {
                //多选
                QHBoxLayout* hlayout[8]; //创建垂直布局
                for(int i = 0; i < count; i++)  //创建count个多选
                {
                    //创建垂直布局
                    hlayout[i] = new QHBoxLayout;

                    //准备选项内容
                    QTextBrowser *content = new QTextBrowser;
                    content->setText(choices[i]);

                    //创建多选图标
                    QCheckBox *checkBox = new QCheckBox;

                    //准备选项图片
                    QLabel *img = new QLabel;
                    img->setFixedWidth(180);
                    img->setFixedHeight(100);
                    QByteArray arry = query.value(QString("imagine"+QString::number(i+1))).toByteArray();
                    if(!arry.isEmpty())
                    {
                        QPixmap outimg;
                        outimg.loadFromData(arry);
                        QPixmap fitpixmap = outimg.scaled(img->width(), img->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);  // 饱满填充
                        img->setPixmap(fitpixmap); //设置图片
                    }
                    //将图片，图标，内容放入布局
                    hlayout[i]->addWidget(checkBox);
                    if(!arry.isEmpty())
                    {
                        hlayout[i]->addWidget(img);
                    }
                    hlayout[i]->addWidget(content);
                }

                //将题目和选项添加到盒子中
                QVBoxLayout *mulbox = new QVBoxLayout;
                mulbox->addWidget(text);
                for(int i = 0; i < count; i++)
                {
                    mulbox->addLayout(hlayout[i]);
                }
                groupBox->setLayout(mulbox);
            }
            pageComboBox->addItem(QString("problem %1").arg(query.at()+1));
            stackedWidget->addWidget(groupBox);

        }
        QGridLayout *gridLayout = new QGridLayout;
        gridLayout->addWidget(pageComboBox);
        gridLayout->addWidget(stackedWidget);
        textbrowser->setLayout(gridLayout);

        connect(pageComboBox, QOverload<int>::of(&QComboBox::activated),
                      stackedWidget, &QStackedWidget::setCurrentIndex);

        textbrowser->show();

        if(isopen)
        {
            //主题中有问题,提交按钮控件打开
            ui->submitButton->setEnabled(true);
        }
        else
        {
            //主题中无问题,提交按钮控件关闭
            ui->submitButton->setEnabled(false);
        }
    }
}


//-------------------------------------提交按钮-------------------------------------
void VotePage::on_submitButton_clicked()
{
    //创建对应主题投票结果的表
    QSqlQuery query;
    QString tmpsql = QString("create table if not exists '%0'(id integer primary key autoincrement, "
                            "question text, option1 int, option2 int,  option3 int, option4 int,"
                            "option5 int, option6 int, option7 int, option8 int, option9 int);").arg(tmptable + "_Votedata");
    if(!query.exec(tmpsql))
    {
        msgBox.setWindowTitle("投票提示");
        msgBox.setText("投票结果表创建失败！");
        msgBox.exec();
    }

    //先判断当前主题是否完成所有作答
    for(int i = 0; i < stackedWidget->count(); i++)
    {

        bool flag = false; //记录当前主题是否所有题目完成作答
        QGroupBox *groupBox = (QGroupBox*)stackedWidget->widget(i); //获取当前栈中的窗口部件
        QVBoxLayout *layoutbox = (QVBoxLayout*)groupBox->layout(); //获取窗口部件中的布局
        int j = 0;
        for(j = 1; j < layoutbox->count(); j++) //检查当前问题下的选项（无论单选还是多选类，都用其父类QAbstractButton指针指向，这样就可以不用区分对象是单选还是多选）
        {
            QAbstractButton *option  = (QAbstractButton*)((QHBoxLayout*)layoutbox->itemAt(j))->itemAt(0)->widget();
            if(option->isChecked())
            {
                flag = true;
            }
        }
        if(!flag)
        {
            //有题目未完成作答，询问是否提交
            QMessageBox msgBox1;
            msgBox1.setWindowIcon(icon_msgBox);
            msgBox1.setStyleSheet("background-image: url(:/background.jpg);");
            msgBox1.setWindowTitle("提交提示");
            msgBox1.setText("当前主题中有问题未完成作答，您是否想要提交呢？");
            msgBox1.setStandardButtons(QMessageBox::Cancel | QMessageBox::Ok);
            msgBox1.setDefaultButton(QMessageBox::Cancel);
            int ret = msgBox1.exec();
            if(ret == QMessageBox::Cancel) //不提交
            {
                return;
            }
            else //提交
            {
                break;
            }
        }
    }

    //------------------------------新版本------------------------
    //统计当前得分
    int index = 0; //记录该主题中第几个问题
    for(int i = 0; i < stackedWidget->count(); i++)
    {
        index = i + 1;
        QGroupBox *groupBox = (QGroupBox*)stackedWidget->widget(i); //获取当前栈中的窗口部件
        QVBoxLayout *layoutbox = (QVBoxLayout*)groupBox->layout(); //获取窗口部件中的布局

        //获取当前题目
        QString question = ((QTextBrowser*)layoutbox->itemAt(0)->widget())->toPlainText();

        //获取当前题目得分
        int score[9] = {0}; //记录当前问题选项的得分情况，初始化为-1代表没有该选项,此处数组大小为8：防止选择最后一个选项时，设置结束标志位时数字越界
        int j = 0;
        for(j = 1; j < layoutbox->count(); j++) //检查当前问题下的选项（无论单选还是多选类，都用其父类QAbstractButton指针指向，这样就可以不用区分对象是单选还是多选）
        {
            QAbstractButton *option  = (QAbstractButton*)((QHBoxLayout*)layoutbox->itemAt(j))->itemAt(0)->widget();
            if(option->isChecked())
            {
                //第i个选项被选中
                score[j - 1] = 1;
            }
        }
        score[j - 1] = -1; //设置为负数，代表选项到i之前就此结束，从i开始后面没有选项，方便统计分数

        //检查当前题目投票是否之前已有其他用户之前投过
        bool state = true;
        tmpsql = QString("select * from '%1';").arg(tmptable+"_Votedata");
        query.exec(tmpsql);
        if(query.seek(index-1))  //定位到当前问题行:如果定位到问题所在行，则说明之前有数据，只需要更新，并且将state = false；如果没有定位到，则之前没有数据,需要进行插入
        {
            int id = query.value("id").toInt(); //获取当前行的id
            tmpsql = QString("update '%0' set option1 = %1, option2 = %2, option3 = %3, option4 = %4, option5 = %5, option6 = %6, option7 = %7, option8 = %8, option9 = %9 where id == %10;")
                             .arg(tmptable+"_Votedata")
                             .arg(query.value("option1").toInt()+score[0]).arg(query.value("option2").toInt()+score[1])
                             .arg(query.value("option3").toInt()+score[2]).arg(query.value("option4").toInt()+score[3])
                             .arg(query.value("option5").toInt()+score[4]).arg(query.value("option6").toInt()+score[5])
                             .arg(query.value("option7").toInt()+score[6]).arg(query.value("option8").toInt()+score[7])
                             .arg(query.value("option9").toInt()+score[8]).arg(id);

            state = false;
        }
        if(state)
        {
            tmpsql = QString("insert into '%0'(question, option1, option2, option3, option4, option5, option6, option7, option8, option9) "
                                     "values('%1', %2, %3, %4, %5, %6, %7, %8, %9, %10);").arg(tmptable+"_Votedata")
                                      .arg(question)
                                      .arg(score[0]).arg(score[1])
                                      .arg(score[2]).arg(score[3])
                                      .arg(score[4]).arg(score[5])
                                      .arg(score[6]).arg(score[7])
                                      .arg(score[8]);
        }
        if(!query.exec(tmpsql))
        {
            msgBox.setWindowTitle("提交提示");
            msgBox.setText("提交问题失败！");
            msgBox.exec();
        }
        else
        {
            QSqlQuery query;
            QString tmpsql = QString(QString("update userdata set '%1' = 1  where user == '%2' and password == '%3';")
                                     .arg(tmptable)
                                     .arg(user)
                                     .arg(password));
            if(!query.exec(tmpsql))
            {
                msgBox.setWindowTitle("提交提示");
                msgBox.setText("用户表标志位设置失败！");
                msgBox.exec();
            }
        }
    }
    msgBox.setWindowTitle("提交提示");
    msgBox.setText("提交成功！");
    msgBox.exec();
    ui->submitButton->setEnabled(false);
}

//------------------------------------------槽函数：接受数据-----用户名和密码------------------------------------------
void VotePage::receive_userdata(QString m_user, QString m_password)
{
    user = m_user;
    password = m_password;
}

//------------------------------------------返回------------------------------------------
void VotePage::on_returnButton_clicked()
{
    LoginWindow* lw = new LoginWindow;
    lw->show();
    this->close();
}
//-------------------------显示结果---------------------------
void VotePage::on_lookButton_clicked()
{
    //转到结果界面
    ResultWindow* rw = new ResultWindow;
    rw->show();
    this->close();
}
