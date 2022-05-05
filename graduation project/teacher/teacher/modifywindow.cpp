#include "modifywindow.h"
#include "ui_modifywindow.h"
#include "loginwindow.h"
#include <QSqlQuery>
ModifyWindow::ModifyWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ModifyWindow)
  ,icon_window(":/shangluo.png")
  ,icon_msgBox(":/message.jpg")
{
    ui->setupUi(this);
    //设置消息盒子图标
    msgBox.setWindowIcon(icon_msgBox);
    msgBox.setWindowTitle("修改提示");
    msgBox.setStyleSheet("background-image: url(:/background.jpg);");

    //登陆界面控件美化
    this->setFixedSize(this->width(),this->height());
    this->setWindowIcon(icon_window);

    QLineEdit* edits[4];
    edits[0] = ui->userlineEdit;
    edits[1] = ui->originalpasswordlineEdit;
    edits[2] = ui->newpasswordlineEdit;
    edits[3] = ui->confirmpasswordlineEdit;
    for(int i= 0; i < 4; i++)
    {
        edits[i]->setStyleSheet("font: 25 14pt '微软雅黑 Light';" //字体
                                "color: rgb(31,31,31);"  //字体颜色
                                "padding-left:20px;"       //内边距-字体缩进
                                "background-color: rgb(255, 255, 255);" //背景颜色
                                "border:2px solid rgb(0, 170, 255);border-radius:15px;");//边框粗细-颜色-圆角设置
    }
    ui->yesButton->setStyleSheet("QPushButton{color: rgb(255,255,255);background-color: rgb(0, 170, 255);"
                                    "border: none;border-radius:15px;}"
                                    "QPushButton:hover{background-color: rgb(22,218,208);}"//hover
                                    "QPushButton:pressed{background-color: rgb(17,171,164);}");//pressed
    ui->returnButton->setStyleSheet("QPushButton{color: rgb(255,255,255);background-color: rgb(0, 170, 255);"
                                    "border: none;border-radius:15px;}"
                                    "QPushButton:hover{background-color: rgb(22,218,208);}"//hover
                                    "QPushButton:pressed{background-color: rgb(17,171,164);}");//pressed
}

ModifyWindow::~ModifyWindow()
{
    delete ui;
}

void ModifyWindow::on_returnButton_clicked()
{
    LoginWindow *lw = new LoginWindow;
    lw->show();
    this->close();
}

void ModifyWindow::on_yesButton_clicked()
{
    //判断输入是否合法
    if(ui->userlineEdit->text() == "" || ui->originalpasswordlineEdit->text() == "" ||
       ui->newpasswordlineEdit->text() == "" || ui->confirmpasswordlineEdit->text() == "")
    {
        msgBox.setText("请输入合理的用户名和密码！");
        msgBox.exec();
        return;
    }

    //判断两次密码是否一致
    if(ui->newpasswordlineEdit->text() != ui->confirmpasswordlineEdit->text())
    {
        msgBox.setText("两次密码输入不一致，请重新输入！");
        msgBox.exec();
        return;
    }

    //更新密码
    QSqlQuery query("select * from userdata;");
    while(query.next())
    {
        if(query.value("user").toString() == ui->userlineEdit->text())
        {
            if(query.value("password").toString() == ui->originalpasswordlineEdit->text())
            {
                //将原来的旧密码改为新的密码
                QString tmpsql = QString("update userdata set password = '%1' where user == '%2';")
                                        .arg(ui->newpasswordlineEdit->text())
                                        .arg(ui->userlineEdit->text());
                if(!query.exec(tmpsql))
                {
                    msgBox.setText("修改失败！");
                    msgBox.exec();
                    break;
                }
                else
                {
                    msgBox.setText("修改成功！");
                    msgBox.exec();
                    ui->userlineEdit->clear();
                    ui->originalpasswordlineEdit->clear();
                    ui->newpasswordlineEdit->clear();
                    break;
                }
            }
            else
            {
                msgBox.setText("用户名和原始密码不匹配，请重新输入！");
                msgBox.exec();
                return;
            }
        }
    }
    msgBox.setText("没有该用户名！");
    msgBox.exec();
}

void ModifyWindow::on_originalButton_clicked(bool checked)
{
    if(checked)
    {
        ui->originalpasswordlineEdit->setEchoMode(QLineEdit::Password);
    }
    else
    {
        ui->originalpasswordlineEdit->setEchoMode(QLineEdit::Normal);
    }
}
void ModifyWindow::on_newButton_clicked(bool checked)
{
    if(checked)
    {
        ui->newpasswordlineEdit->setEchoMode(QLineEdit::Password);
    }
    else
    {
        ui->newpasswordlineEdit->setEchoMode(QLineEdit::Normal);
    }
}

void ModifyWindow::on_confirmnewButton_clicked(bool checked)
{
    if(checked)
    {
        ui->newpasswordlineEdit->setEchoMode(QLineEdit::Password);
    }
    else
    {
        ui->newpasswordlineEdit->setEchoMode(QLineEdit::Normal);
    }
}
