#include "setwindow.h"
#include "ui_setwindow.h"
#include <QTextBrowser>
#include <QInputDialog>
#include <QPixmap>
#include <QBuffer>
#include <QSqlRecord>
#include <QTextImageFormat>
#include <QFileDialog>
#include <QTextBlock>
#include <QAxObject>
#include "votepage.h"
#include "loginwindow.h"
SetWindow::SetWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SetWindow)
    ,msgBox(QMessageBox::Information, "温馨提示", "")
  ,icon_window(":/shangluo.png")
  ,icon_msgBox(":/message.jpg")
  ,icon_modify(":/modify.jpg")
{

    ui->setupUi(this);
    //设置界面美化
    this->setFixedSize(this->width(),this->height());
    this->setWindowIcon(icon_window);
    this->setStyleSheet("QMainWindow{background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(251,102,102, 200), stop:1 rgba(20,196,188, 210));}");
    ui->displaylabel->setStyleSheet("background-color: rgb(255, 255, 255);"
                                    "border:2px solid rgb(20,196,188); border-radius:15px;");//边框粗细-颜色-圆角设置
    ui->operationgroupBox->setStyleSheet("background-color: rgb(152, 152, 152); border:3px solid rgb(255,255,255); border-radius:20px;");//边框粗细-颜色-圆角设置

    QPushButton* buttons[16];
    buttons[0] = ui->themeButton;
    buttons[1] = ui->deletethemeButton;
    buttons[2] = ui->exportButton;
    buttons[3] = ui->addButton;
    buttons[4] = ui->canceladdButton;
    buttons[5] = ui->confirmButton;
    buttons[6] = ui->modifyButton;
    buttons[7] = ui->cancelmodifyButton;
    buttons[8] = ui->confirmmodifyButton;
    buttons[9] = ui->deletequestionButton;
    buttons[10] = ui->nextButton;
    buttons[11] = ui->upButton;
    buttons[12] = ui->choicespushButton;
    buttons[13] = ui->optionButton;
    buttons[14] = ui->returnButton;
    buttons[15] = ui->searchButton;
    for(int i = 0; i < 16; i++)
    {
        buttons[i]->setStyleSheet("QPushButton{background-color: rgb(255, 255, 255);"
                                  "border: none;border-radius:15px;}"
                                  "QPushButton:hover{background-color: rgb(22,218,208);}"//hover
                                  "QPushButton:pressed{background-color: rgb(17,171,164);}");//pressed
    }
    //设置消息盒子图标
    msgBox.setWindowIcon(icon_msgBox);
    msgBox.setStyleSheet("background-image: url(:/background.jpg);");


//    //--------------设置图片
//    QTextImageFormat imageFormat;
//    imageFormat.setName("C:/Users/15829954738/Desktop/set.jpg");
//    ui->img1->textCursor().insertImage(imageFormat);

//    //--------------获取图片
//    QTextDocument *document = ui->img1->document();
//    QTextBlock block = document->begin();
//    QTextCharFormat format = block.begin().fragment().charFormat();
//    bool isImage = format.isImageFormat();
//    if(isImage)
//    {
//        QTextImageFormat imgf = format.toImageFormat();
//        qDebug() << "imgf = " << imgf.name();
//    }

    //初始化布局编辑框,方便后面使用
    layouts[0] = ui->Layout1;
    layouts[1] = ui->Layout2;
    layouts[2] = ui->Layout3;
    layouts[3] = ui->Layout4;
    layouts[4] = ui->Layout5;
    layouts[5] = ui->Layout6;
    layouts[6] = ui->Layout7;
    layouts[7] = ui->Layout8;
    for(int i = 0; i < 8; i++)
    {
        TextEdit *img = new TextEdit;
        img->setEnabled(false);
        img->setPlaceholderText("插入图片");
        imgs[i] = img;
        layouts[i]->addWidget(img);
    }
    //将7个选项放入数组中，方便后面使用
    edits[0] = ui->optionEdit1;
    edits[1] = ui->optionEdit2;
    edits[2] = ui->optionEdit3;
    edits[3] = ui->optionEdit4;
    edits[4] = ui->optionEdit5;
    edits[5] = ui->optionEdit6;
    edits[6] = ui->optionEdit7;
    edits[7] = ui->optionEdit8;
    //初始化三个选项并隐藏后三个选项
    boxs[0] = ui->optionBox1;
    boxs[1] = ui->optionBox2;
    boxs[2] = ui->optionBox3;
    boxs[3] = ui->optionBox4;
    count = 0;
    for(int i = 0; i < 4; i++)
    {
        boxs[i]->hide();
    }
    //初始化当前表的索引
    index = 0;

    //将已有主题表显示在控件上
    QSqlQuery query;
    QString tmpsql = QString("select * from tablename;");
    if(query.exec(tmpsql))
    {
        while(query.next())
        {
            ui->displaylistWidget->addItem(query.value("themename").toString());
        }
    }
    else
    {
        msgBox.setText("控件更新失败！");
        msgBox.exec();
    }

    //默认问题为单选
    ischoice = false;
}

SetWindow::~SetWindow()
{
    delete ui;
    for(int i = 0; i < 8; i++)
    {
        delete imgs[i];
    }
}


//——————————————————————————————————双击列表控件按钮——————————————————————————————————
void SetWindow::on_displaylistWidget_itemDoubleClicked(QListWidgetItem *item)
{
    //先清除当前编辑控件
    ui->questionEdit->clear();
    for(int i = 0; i < 8; i++)
    {
        imgs[i]->clear();
        edits[i]->clear();
    }
    //更新index
    index = 0;
    //先将多余的选项隐藏，需要时自动显示
    count = 0;
    for(int i = 0; i < 4; i++)
    {
        boxs[i]->hide();
    }
    //设置当前主题
    ui->displaylabel->setText(item->text());
    //获取该主题对应的数据表名
    QSqlQuery query("select * from tablename;");
    while(query.next())
    {
        if(query.value("themename").toString() == item->text())
        {
            tmptable = query.value("number").toString();
            break;
        }
    }
    //将主题中的第一个问题显示在控件上并显示相应按钮
    QString tmpsql = QString("select * from '%1'").arg(tmptable);
    query.exec(tmpsql);
    if(query.first()) //如果为真，则表中有问题和选项
    {
        //设置问题是单选还是多选
        if(query.value("state").toInt() == 0)//单选
        {
            if(ui->choicespushButton->text() == "多选")
            {
                ui->choicespushButton->setText("单选");
                ischoice = false;
            }
        }
        else //多选
        {
            if(ui->choicespushButton->text() == "单选")
            {
                ui->choicespushButton->setText("多选");
                ischoice = true;
            }
        }

        ui->questionEdit->setText(query.value("question").toString()); //设置问题
        int i = 0;
        QString tmp;
        while(i < 8 && "" != (tmp = query.value(QString("option%1").arg(i+1)).toString()))  //设置选项
        {
            //设置选项
            edits[i]->setText(tmp);
            if(i >= 4)
            {
                //将多余的按钮显示
                boxs[i - 4]->show();
                count = i - 4 + 1;
            }
            i++;
        }

        //设置选项图片
        i = 0;
        while(i < 8)
        {
            QByteArray arry = query.value(QString("imagine"+QString::number(i+1))).toByteArray();
            if(!arry.isEmpty())
            {
                QImage image;
                image.loadFromData(arry);
                if(!image.isNull())
                {
                    imgs[i]->textCursor().insertImage(image);
                }
            }
            i++;
        }
        //关闭编辑控件的使能功能
        ui->questionEdit->setEnabled(false);
        for(int i = 0; i < 8; i++)
        {
            edits[i]->setEnabled(false);
        }


        ui->upButton->setEnabled(true);
        ui->nextButton->setEnabled(true);
        ui->deletequestionButton->setEnabled(true);
        ui->modifyButton->setEnabled(true);
        ui->searchButton->setEnabled(true);
    }
    else
    {
        //该主题中没有问题，请添加
        msgBox.setWindowTitle("温馨提示");
        msgBox.setText("当前主题中无问题，如需要问题请添加！");
        msgBox.exec();
        ui->upButton->setEnabled(false);
        ui->nextButton->setEnabled(false);
        ui->deletequestionButton->setEnabled(false);
        ui->modifyButton->setEnabled(false);
        ui->searchButton->setEnabled(false);
    }
    ui->confirmButton->setEnabled(false);
    ui->confirmmodifyButton->setEnabled(false);
    ui->canceladdButton->setEnabled(false);
    ui->cancelmodifyButton->setEnabled(false);
    ui->deletethemeButton->setEnabled(true);
    ui->addButton->setEnabled(true);
    ui->deletethemeButton->setEnabled(true);
}


//——————————————————————————————————添加主题——————————————————————————————————
void SetWindow::on_themeButton_clicked()
{
    QSqlQuery query;
    QString tmpsql;
    //创建输入对话框:获取主题名
    bool ok;
    QInputDialog inputDialog;
    inputDialog.setWindowIcon(icon_modify);
    QString theme_name = inputDialog.getText(this, "添加主题", "主题名：", QLineEdit::Normal, "", &ok);
    if(!ok || theme_name.isEmpty())
        return;

    if(!theme_name.isEmpty())
    {
        //将新主题添加到主题表中
        int num;
        while(1)
        {
            bool state = false;
            int i = rand() % 100;
            tmpsql = QString("select * from tablename");
            query.exec(tmpsql);
            while(query.next())
            {
                if(query.value("number").toInt() == QString("Theme_%1").arg(QString::number(i)))
                {
                    state = true;
                    break;
                }
                if(query.value("themename").toString() == theme_name)
                {
                    msgBox.setWindowTitle("添加主题提示");
                    msgBox.setText("该主题已经被添加过，请重新输入！");
                    msgBox.exec();
                    return;
                }
            }
            if(!state)
            {
                num = i;
                tmpsql = QString("insert into tablename(number, themename) values('%1', '%2');")
                                                           .arg("Theme_" + QString::number(num))
                                                           .arg(theme_name);
                if(!query.exec(tmpsql))
                {
                    msgBox.setWindowTitle("添加主题提示");
                    msgBox.setText("主题添加失败！");
                    msgBox.exec();
                    return;
                }
                break;
            }
        }

        //创建存放该主题中问题的数据表:state字段是判断多选还是单选
        tmpsql = QString("create table if not exists '%1'(id integer primary key autoincrement,"
                                 "state int, question text, imagine1 blob, option1 text, imagine2 blob, option2 text, imagine3 blob, option3 text,"
                                 "imagine4 blob, option4 text, imagine5 blob, option5 text, imagine6 blob, option6 text, imagine7 blob, option7 text, imagine8 blob, option8 text);").arg("Theme_" + QString::number(num));
        if(!query.exec(tmpsql))
        {
            msgBox.setWindowTitle("添加主题提示");
            msgBox.setText("主题添加失败！");
            msgBox.exec();
            return;
        }

        //获取成功,更新在UI控件上
        ui->displaylistWidget->addItem(theme_name);


        //更新用户表:添加字段，并设置为0
        tmpsql = QString("alter table userdata add column '%1' int;").arg("Theme_" + QString::number(num));
        if(!query.exec(tmpsql))
        {
            msgBox.setWindowTitle("添加主题提示");
            msgBox.setText("添加主题失败！");
            msgBox.exec();
        }
        tmpsql = QString("update userdata set '%1' = 0;").arg("Theme_" + QString::number(num));
        if(!query.exec(tmpsql))
        {
            msgBox.setWindowTitle("添加主题提示");
            msgBox.setText("添加主题失败！");
            msgBox.exec();
        }
    }
}

//——————————————————————————————————删除主题——————————————————————————————————
void SetWindow::on_deletethemeButton_clicked()
{
    //删除整个主题
    QSqlQuery query("select * from tablename;");
    while(query.next())  //删除主题表中对应的行
    {
        if(query.value("themename").toString() == ui->displaylabel->text())
        {
            QString str = QString("delete from tablename where number == '%1';").arg(tmptable);
            query.exec(str);
            break;
        }
    }

    QString tmpsql = QString("drop table '%1';").arg(tmptable); //删除存放问题的表
    if(query.exec(tmpsql))
    {
        //并且删除主题对应的存放投票数据的表
        tmpsql = QString("drop table '%1';").arg(tmptable+"_Votedata");
        query.exec(tmpsql);

        //删除存放用户信息表中该主题的标志位（删除该主题对应的字段）
        //方法如下
        QString themelist = ""; //准备新表的字段（字段后要类型）
        QString copylist = ""; //准备要复制的字段（字段后无类型）
        tmpsql = QString("select * from tablename;");
        query.exec(tmpsql);
        while(query.next())
        {
            if(query.value("number").toString() != tmptable)
            {
                themelist += ", " + query.value("number").toString() + " int"; //此处主要，如果字段是数字的话，要加单引号，创建表的时候才可以被识别出
                copylist += ", " + query.value("number").toString();
            }
        }
        //1.先创建一个新用户表
        tmpsql = QString("create table if not exists tempuserdata(id integer primary key autoincrement, user text, password text, telephone text);").insert(118, themelist);
        if(!query.exec(tmpsql))
        {
            msgBox.setWindowTitle("删除主题提示");
            msgBox.setText("新表创建失败！");
            msgBox.exec();
            return;
        }
        //2.将旧用户表内容复制到新表
        tmpsql = QString("insert into tempuserdata(user, password, telephone) select user, password, telephone from userdata;")
                         .insert(84, copylist)
                         .insert(50, copylist);
        if(!query.exec(tmpsql))
        {
            msgBox.setWindowTitle("删除主题提示");
            msgBox.setText("内容复制失败！");
            msgBox.exec();
            return;
        }
        //3.将旧表删除
        tmpsql = QString("drop table userdata;");
        if(!query.exec(tmpsql))
        {
            msgBox.setWindowTitle("删除主题提示");
            msgBox.setText("旧表删除失败！");
            msgBox.exec();
            return;
        }
        //4.将旧表重新命名
        tmpsql = QString("alter table tempuserdata rename to userdata;");
        if(!query.exec(tmpsql))
        {
            msgBox.setWindowTitle("删除主题提示");
            msgBox.setText("旧表名更新失败！");
            msgBox.exec();
            return;
        }
        msgBox.setText("删除主题成功！");
        msgBox.exec();

        //删除UI控件上的主题名
        QListWidgetItem* item = ui->displaylistWidget->currentItem();
        ui->displaylistWidget->removeItemWidget(item);
        delete item;


        //清除编辑控件
        ui->displaylabel->clear();
        ui->questionEdit->clear();
        for(int i = 0; i < 8; i++)
        {
            imgs[i]->clear();
            edits[i]->clear();
        }

        //隐藏多余的编辑控件
        for(int i = 0; i < 4; i++)
        {
            boxs[i]->hide();
        }
        count = 0;
    }
    ui->deletethemeButton->setEnabled(false);
    ui->upButton->setEnabled(false);
    ui->nextButton->setEnabled(false);
    ui->deletequestionButton->setEnabled(false);
    ui->canceladdButton->setEnabled(false);
    ui->cancelmodifyButton->setEnabled(false);
    ui->modifyButton->setEnabled(false);
    ui->addButton->setEnabled(false);
    ui->searchButton->setEnabled(false);
}


//——————————————————————————————————添加问题——————————————————————————————————
void SetWindow::on_addButton_clicked()
{

    //显示编辑控件
    ui->questionEdit->setEnabled(true);
    ui->questionEdit->clear();
    for(int i = 0; i < 8; i++)
    {
        //设置图片编辑框
        imgs[i]->setEnabled(true);
        imgs[i]->clear();
        //设置选项编辑框
        edits[i]->setEnabled(true);
        edits[i]->clear();
    }
    //隐藏多余编辑控件
    count = 0;
    for(int i = 0; i < 4; i++)
    {
        boxs[i]->hide();
    }
    //显示确认按钮
    ui->confirmButton->setEnabled(true);
    ui->canceladdButton->setEnabled(true);
    ui->addButton->setEnabled(false);
    ui->choicespushButton->setEnabled(true);
    //显示添加选项按钮
    ui->optionButton->setEnabled(true);
    ui->upButton->setEnabled(false);
    ui->nextButton->setEnabled(false);
    ui->modifyButton->setEnabled(false);
    ui->confirmmodifyButton->setEnabled(false);
    ui->cancelmodifyButton->setEnabled(false);
    ui->deletethemeButton->setEnabled(false);
    ui->deletequestionButton->setEnabled(false);
    ui->searchButton->setEnabled(false);
}


//——————————————————————————————————取消添加问题——————————————————————————————————
void SetWindow::on_canceladdButton_clicked()
{
    //设置相关按钮
    ui->questionEdit->setEnabled(false);
    ui->questionEdit->clear();
    for(int i = 0; i < 8; i++)
    {
        //设置图片编辑框
        imgs[i]->setEnabled(false);
        imgs[i]->clear();
        //设置选项编辑框
        edits[i]->setEnabled(false);
        edits[i]->clear();
    }
    //隐藏多余编辑控件
    count = 0;
    for(int i = 0; i < 4; i++)
    {
        boxs[i]->hide();
    }
    //显示确认按钮
    ui->confirmButton->setEnabled(false);
    ui->canceladdButton->setEnabled(false);
    ui->addButton->setEnabled(true);
    ui->choicespushButton->setEnabled(false);
    //显示添加选项按钮
    ui->optionButton->setEnabled(false);
    ui->confirmmodifyButton->setEnabled(false);
    ui->cancelmodifyButton->setEnabled(false);
    ui->deletethemeButton->setEnabled(true);

    //将刚才的问题显示出来
    if(index >= 0)
    {
        QSqlQuery query(QString("select * from '%1';").arg(tmptable));
        if(query.seek(index))
        {
            //设置问题是单选还是多选
            if(query.value("state").toInt() == 0)//单选
            {
                if(ui->choicespushButton->text() == "多选")
                {
                    ui->choicespushButton->setText("单选");
                    ischoice = false;
                }
            }
            else //多选
            {
                if(ui->choicespushButton->text() == "单选")
                {
                    ui->choicespushButton->setText("多选");
                    ischoice = true;
                }
            }

            ui->questionEdit->setText(query.value("question").toString()); //设置问题
            int i = 0;
            QString tmp;
            while(i < 8 && "" != (tmp = query.value(QString("option%1").arg(i+1)).toString()))  //设置选项
            {
                //设置选项
                edits[i]->setText(tmp);
                if(i >= 4)
                {
                    //将多余的按钮显示
                    boxs[i - 4]->show();
                    count = i - 4 + 1;
                }
                i++;
            }

            //设置选项图片
            i = 0;
            while(i < 8)
            {
                QByteArray arry = query.value(QString("imagine"+QString::number(i+1))).toByteArray();
                if(!arry.isEmpty())
                {
                    QImage image;
                    image.loadFromData(arry);
                    if(!image.isNull())
                    {
                        imgs[i]->textCursor().insertImage(image);
                    }
                }
                i++;
            }
        }
    }

    if(!ui->questionEdit->toPlainText().isEmpty())
    {
        ui->modifyButton->setEnabled(true);
        ui->upButton->setEnabled(true);
        ui->nextButton->setEnabled(true);
        ui->deletequestionButton->setEnabled(true);
        ui->searchButton->setEnabled(true);
    }
}


//——————————————————————————————————确定添加问题——————————————————————————————————
void SetWindow::on_confirmButton_clicked()
{
    //检查输入问题是否合法
    if(ui->questionEdit->toPlainText() == "")
    {
        msgBox.setWindowTitle("添加提示");
        msgBox.setText("添加问题失败，请输入合法的问题和选项！");
        msgBox.exec();
        return;
    }
    //检查当前问题是否已经出现过
    bool flag = false; //记录当前主题是否有问题，用于后面设置控件的使能功能
    int num = 0; //用于更新Index
    QSqlQuery query(QString("select * from '%1';").arg(tmptable));
    while(query.next())
    {
        num++;
        flag = true;
        if(query.value("question").toString() == ui->questionEdit->toPlainText())
        {
            msgBox.setWindowTitle("添加提示");
            msgBox.setText("当前问题与之前问题重复，请重新输入！");
            msgBox.exec();
            return;
        }
    }
    int val = 0;
    if(ischoice)
    {
        val = 1;
    }
    //向数据库中对应表中增加问题(插入),图片和文本分开插入
    //1.先插入文本
    QString tmpsql = QString("insert into '%0'(state, question, option1, option2, option3, option4, option5, option6, option7, option8) "
                                    "values(%1, '%2', '%3', '%4', '%5', '%6', '%7', '%8', '%9', '%10');")
                                    .arg(tmptable)
                                    .arg(val)
                                    .arg(ui->questionEdit->toPlainText())
                                    .arg(edits[0]->toPlainText())
                                    .arg(edits[1]->toPlainText())
                                    .arg(edits[2]->toPlainText())
                                    .arg(edits[3]->toPlainText())
                                    .arg(edits[4]->toPlainText())
                                    .arg(edits[5]->toPlainText())
                                    .arg(edits[6]->toPlainText())
                                    .arg(edits[7]->toPlainText());
    if(!query.exec(tmpsql))
    {
        msgBox.setWindowTitle("添加提示");
        msgBox.setText("添加问题失败！");
        msgBox.exec();
    }
    else
    {
        //2.插入图片
        bool ok = true;
        for(int i = 0; i < 8; i++)
        {
            QTextDocument *document = imgs[i]->document();
            if(!document->isEmpty())
            {
                QTextBlock block = document->begin();
                QTextCharFormat format = block.begin().fragment().charFormat();
                bool isImage = format.isImageFormat();
                if(isImage)  //检查是否是图片，不是图片不插入
                {
                    QTextImageFormat imgf = format.toImageFormat();
                    QFile inimg;
                    inimg.setFileName(imgf.name().remove(0,8));
                    if(!inimg.open(QIODevice::ReadOnly)) //读的方式打开
                    {
                        msgBox.setWindowTitle("添加提示");
                        msgBox.setText("图片加载失败！");
                        msgBox.exec();
                        ok = false;
                    }
                    QByteArray arry = inimg.readAll();
                    query.prepare(QString("update '%0' set '%1' = :imgdata where question == '%2';")
                                  .arg(tmptable)
                                  .arg(QString("imagine"+QString::number(i+1)))
                                  .arg(ui->questionEdit->toPlainText()));
                    query.bindValue(":imgdata", arry);
                    if(!query.exec())
                    {
                        msgBox.setWindowTitle("添加提示");
                        msgBox.setText("图片插入失败！");
                        msgBox.exec();
                        ok = false;
                    }
                }
            }
        }
        if(ok)
        {
            msgBox.setWindowTitle("添加提示");
            msgBox.setText("添加问题成功！");
            msgBox.exec();
            index = num; //num直接赋值给index,因为Index是从0开始的
            flag = true;
        }
        else
        {
            if(index >= 0)
            {
                //添加失败,恢复到原来的问题
                QSqlQuery query(QString("select * from '%1';").arg(tmptable));
                if(query.seek(index))
                {
                    //设置问题是单选还是多选
                    if(query.value("state").toInt() == 0)//单选
                    {
                        if(ui->choicespushButton->text() == "多选")
                        {
                            ui->choicespushButton->setText("单选");
                            ischoice = false;
                        }
                    }
                    else //多选
                    {
                        if(ui->choicespushButton->text() == "单选")
                        {
                            ui->choicespushButton->setText("多选");
                            ischoice = true;
                        }
                    }

                    ui->questionEdit->setText(query.value("question").toString()); //设置问题
                    int i = 0;
                    QString tmp;
                    while(i < 8 && "" != (tmp = query.value(QString("option%1").arg(i+1)).toString()))  //设置选项
                    {
                        //设置选项
                        edits[i]->setText(tmp);
                        if(i >= 4)
                        {
                            //将多余的按钮显示
                            boxs[i - 4]->show();
                            count = i - 4 + 1;
                        }
                        i++;
                    }

                    //设置选项图片
                    i = 0;
                    while(i < 8)
                    {
                        QByteArray arry = query.value(QString("imagine"+QString::number(i+1))).toByteArray();
                        if(!arry.isEmpty())
                        {
                            QImage image;
                            image.loadFromData(arry);
                            if(!image.isNull())
                            {
                                imgs[i]->textCursor().insertImage(image);
                            }
                        }
                        i++;
                    }
                }
            }
        }
    }
    //隐藏编辑控件
    ui->questionEdit->setEnabled(false);
    for(int i = 0; i < 8; i++)
    {
        //设置图片编辑框
        imgs[i]->setEnabled(false);

        //设置文本编辑框
        edits[i]->setEnabled(false);
    }
    //显示确认按钮
    ui->confirmButton->setEnabled(false);
    ui->canceladdButton->setEnabled(false);
    ui->addButton->setEnabled(true);
    ui->choicespushButton->setEnabled(false);
    ui->optionButton->setEnabled(false);
    ui->cancelmodifyButton->setEnabled(false);
    ui->deletethemeButton->setEnabled(true);
    if(flag)
    {
        ui->modifyButton->setEnabled(true);
        ui->upButton->setEnabled(true);
        ui->nextButton->setEnabled(true);
        ui->deletequestionButton->setEnabled(true);
        ui->searchButton->setEnabled(true);
    }
}

//——————————————————————————————————修改当前问题——————————————————————————————————
void SetWindow::on_modifyButton_clicked()
{
    //将选项按钮使能功能打开
    ui->questionEdit->setEnabled(true);
    for(int i = 0; i < 8; i++)
    {
        imgs[i]->setEnabled(true);
        edits[i]->setEnabled(true);
    }
    ui->choicespushButton->setEnabled(true);
    ui->modifyButton->setEnabled(false);
    ui->confirmmodifyButton->setEnabled(true);
    ui->cancelmodifyButton->setEnabled(true);
    ui->addButton->setEnabled(false);
    ui->deletethemeButton->setEnabled(false);
    ui->deletequestionButton->setEnabled(false);
    ui->optionButton->setEnabled(true);
    ui->upButton->setEnabled(false);
    ui->nextButton->setEnabled(false);
    ui->searchButton->setEnabled(false);
}



//——————————————————————————————————取消修改当前问题——————————————————————————————————
void SetWindow::on_cancelmodifyButton_clicked()
{
    //将选项按钮使能功能打开
    ui->questionEdit->setEnabled(false);
    for(int i = 0; i < 8; i++)
    {
        imgs[i]->setEnabled(false);
        edits[i]->setEnabled(false);
    }
    ui->choicespushButton->setEnabled(false);
    ui->modifyButton->setEnabled(true);
    ui->cancelmodifyButton->setEnabled(false);
    ui->confirmmodifyButton->setEnabled(false);
    ui->addButton->setEnabled(true);
    ui->deletethemeButton->setEnabled(true);
    ui->deletequestionButton->setEnabled(true);
    ui->optionButton->setEnabled(false);
    ui->upButton->setEnabled(true);
    ui->nextButton->setEnabled(true);
    ui->searchButton->setEnabled(true);
}

//——————————————————————————————————确认修改当前问题——————————————————————————————————
void SetWindow::on_confirmmodifyButton_clicked()
{
    int val = 0;
    if(ischoice)
    {
        val = 1;
    }
    QSqlQuery query(QString("select * from '%1';").arg(tmptable)); //查找要修改的问题id
    query.seek(index);
    int id = query.value("id").toInt();
    QString tmpsql = QString("update '%0' set state = %1, question = '%2' where id == %3;").arg(tmptable).arg(val).arg(ui->questionEdit->toPlainText()).arg(id); //修改当前问题以及选项状态（单选还是多选）
    if(query.exec(tmpsql))
    {
        //题目修改成功
        for(int i = 0; i < 8; i++) //修改当前选项
        {
            QString tmpsql = QString("update '%1' set option%2 = '%3' where id == %4;").arg(tmptable).arg(i+1).arg(edits[i]->toPlainText()).arg(id);
            if(!query.exec(tmpsql))
            {
                msgBox.setText("修改问题失败！");
                msgBox.exec();
            }
        }

        for(int i = 0; i < 8; i++) //修改选项的图片
        {
            QTextDocument *document = imgs[i]->document();
            if(!document->isEmpty())
            {
                QTextBlock block = document->begin();
                QTextCharFormat format = block.begin().fragment().charFormat();
                bool isImage = format.isImageFormat();
                if(isImage)
                {
                    QTextImageFormat imgf = format.toImageFormat();
                    if(document->resource(QTextDocument::ImageResource, imgf.name()).canConvert<QImage>())
                    {
                        QVariant var = document->resource(QTextDocument::ImageResource, imgf.name());
                        QImage image = QImage(var.value<QImage>());
                        QByteArray arry;
                        QBuffer buffer(&arry);
                        buffer.open(QIODevice::WriteOnly);
                        image.save(&buffer, "PNG");
                        query.prepare(QString("update '%0' set '%1' = :imgdata where id == %2;")
                                      .arg(tmptable)
                                      .arg(QString("imagine"+QString::number(i+1)))
                                      .arg(id));
                        query.bindValue(":imgdata", arry);
                        if(!query.exec())
                        {
                            msgBox.setWindowTitle("添加提示");
                            msgBox.setText("图片修改失败！");
                            msgBox.exec();
                        }
                    }
                }
            }
            else
            {
                QByteArray arry;
                query.prepare(QString("update '%0' set '%1' = :imgdata where id == %2;")
                              .arg(tmptable)
                              .arg(QString("imagine"+QString::number(i+1)))
                              .arg(id));
                query.bindValue(":imgdata", arry);
                if(!query.exec())
                {
                    msgBox.setWindowTitle("添加提示");
                    msgBox.setText("图片修改失败！");
                    msgBox.exec();
                }
            }
        }
        //清除存放该问题的投票结果表中对应的数据
        tmpsql = QString("update '%1' set option1 = 0, option2 = 0, option3 = 0, option4 = 0, option5 = 0, option6 = 0, option7 = 0, option8 = 0 where id == %2;")
                         .arg(tmptable+"_Votedata")
                         .arg(id);
        query.exec(tmpsql);
    }
    else
    {
         msgBox.setText("修改问题失败！");
         msgBox.exec();
    }
    //将选项按钮使能功能关闭
    ui->questionEdit->setEnabled(false);
    for(int i = 0; i < 8; i++)
    {
        imgs[i]->setEnabled(false);
        edits[i]->setEnabled(false);
    }
    ui->choicespushButton->setEnabled(false);
    ui->modifyButton->setEnabled(true);
    ui->confirmmodifyButton->setEnabled(false);
    ui->cancelmodifyButton->setEnabled(false);
    ui->addButton->setEnabled(true);
    ui->deletethemeButton->setEnabled(true);
    ui->deletequestionButton->setEnabled(true);
    ui->optionButton->setEnabled(false);
    ui->upButton->setEnabled(true);
    ui->nextButton->setEnabled(true);
    ui->searchButton->setEnabled(true);
}

//——————————————————————————————————删除问题——————————————————————————————————
void SetWindow::on_deletequestionButton_clicked()
{
    QSqlQuery query(QString("select * from '%1';").arg(tmptable));
    query.seek(index); //将索引先定位到当前表中的行
    int id = query.value("id").toInt(); //查找要删除的问题id
    QString tmpsql = QString("delete from '%1' where id == %2;").arg(tmptable).arg(id);
    if(query.exec(tmpsql))
    {
        //删除成功
        index--;
        msgBox.setWindowTitle("删除提示");
        msgBox.setText("删除问题成功！");
        msgBox.exec();
        //清除存放该问题投票数据的表中对应的数据
        tmpsql = QString("delete from '%1' where id == %2;").arg(tmptable + "_Votedata").arg(id);
        query.exec(tmpsql);
        //清理控件按钮
        ui->questionEdit->clear();
        for(int i = 0; i < 8; i++)
        {
            imgs[i]->clear();
            edits[i]->clear();
        }
    }
    else
    {
        msgBox.setWindowTitle("删除提示");
        msgBox.setText("删除问题失败！");
        msgBox.exec();
    }
    ui->upButton->setEnabled(false);
    ui->nextButton->setEnabled(false);
    ui->modifyButton->setEnabled(false);
    ui->deletequestionButton->setEnabled(false);
    ui->searchButton->setEnabled(false);
}

//——————————————————————————————————单选或多选——————————————————————————————————
void SetWindow::on_choicespushButton_clicked()
{
    if(ischoice)
    {
        ui->choicespushButton->setText("单选");
        ischoice = false;
    }
    else
    {
        ui->choicespushButton->setText("多选");
        ischoice = true;
    }

}


//——————————————————————————————————增加选项——————————————————————————————————
void SetWindow::on_optionButton_clicked()
{
    if(4 == count)
    {
        msgBox.setWindowTitle("增加选项提示");
        msgBox.setText("无法增加选项，最多增加4个！");
        msgBox.exec();
        return;
    }
    edits[4 + count]->clear();
    boxs[count]->show();
    count++;
}


//——————————————————————————————————返回——————————————————————————————————
void SetWindow::on_returnButton_clicked()
{
    //转到登陆页面
    LoginWindow* lw = new LoginWindow;
    lw->show();
    this->close();
}

//——————————————————————————————————上一个问题——————————————————————————————————
void SetWindow::on_upButton_clicked()
{
    index--;
    QSqlQuery query(QString("select * from '%1'").arg(tmptable));
    if(query.seek(index))  //有上一个记录
    {
        //设置当前问题是多选还是单选
        if(query.value("state").toInt() == 0)
        {
            if(ui->choicespushButton->text() == "多选")
            {
                ui->choicespushButton->setText("单选");
                ischoice = false;
            }
        }
        else
        {
            if(ui->choicespushButton->text() == "单选")
            {
                ui->choicespushButton->setText("多选");
                ischoice = true;
            }
        }

        //先清理一下编辑控件
        ui->questionEdit->clear();
        for(int i = 0; i < 8; i++)
        {
            imgs[i]->clear();
            edits[i]->clear();
        }
        //先将多余的选项隐藏，需要时自动显示
        count = 0;
        for(int i = 0; i < 4; i++)
        {
            boxs[i]->hide();
        }

        ui->questionEdit->setText(query.value("question").toString());  //设置问题
        int i = 0;
        QString tmp;
        while(i < 8 && "" != (tmp = query.value(QString("option%1").arg(i+1)).toString()))  //设置选项
        {
            edits[i]->setText(tmp);
            if(i >= 4)
            {
                //将多余的按钮显示
                boxs[i - 4]->show();
                count = i - 4 + 1;
            }
            i++;
        }
        //设置选项图片
        i = 0;
        while(i < 8)
        {
            QByteArray arry = query.value(QString("imagine"+QString::number(i+1))).toByteArray();
            if(!arry.isEmpty())
            {
                QImage image;
                image.loadFromData(arry);
                if(!image.isNull())
                {
                    imgs[i]->textCursor().insertImage(image);
                }
            }
            i++;
        }
    }
    else  //无上一个记录
    {
        msgBox.setWindowTitle("温馨提示");
        msgBox.setText("无上一个问题！");
        msgBox.exec();
        index++;
    }
}

//——————————————————————————————————下一个问题——————————————————————————————————
void SetWindow::on_nextButton_clicked()
{
    index++;
    QSqlQuery query(QString("select * from '%1'").arg(tmptable));
    if(query.seek(index))  //有下一个记录
    {
        //设置当前问题是多选还是单选
        if(query.value("state").toInt() == 0)
        {
            if(ui->choicespushButton->text() == "多选")
            {
                ui->choicespushButton->setText("单选");
                ischoice = false;
            }
        }
        else
        {
            if(ui->choicespushButton->text() == "单选")
            {
                ui->choicespushButton->setText("多选");
                ischoice = true;
            }
        }

        //先清理一下编辑控件
        ui->questionEdit->clear();
        for(int i = 0; i < 8; i++)
        {
            imgs[i]->clear();
            edits[i]->clear();
        }
        //先将多余的选项隐藏，需要时自动显示
        count = 0;
        for(int i = 0; i < 4; i++)
        {
            boxs[i]->hide();
        }

        ui->questionEdit->setText(query.value("question").toString());  //设置问题
        int i = 0;
        QString tmp;
        while(i < 8 && "" != (tmp = query.value(QString("option%1").arg(i+1)).toString()))  //设置选项
        {
            edits[i]->setText(tmp);
            if(i >= 4)
            {
                //将多余的按钮显示
                boxs[i - 4]->show();
                count = i - 4 + 1;
            }
            i++;
        }

        //设置选项图片
        i = 0;
        while(i < 8)
        {
            QByteArray arry = query.value(QString("imagine"+QString::number(i+1))).toByteArray();
            if(!arry.isEmpty())
            {
                QImage image;
                image.loadFromData(arry);
                if(!image.isNull())
                {
                    imgs[i]->textCursor().insertImage(image);
                }
            }
            i++;
        }

    }
    else  //无下一个记录
    {
        msgBox.setWindowTitle("温馨提示");
        msgBox.setText("无下一个问题！");
        msgBox.exec();
        index--;
    }
}


//——————————————————————————————————搜索问题——————————————————————————————————
void SetWindow::on_searchButton_clicked()
{
    //创建输入对话框:获取题目
    bool ok;
    QInputDialog inputDialog;
    inputDialog.setWindowIcon(icon_modify);
    QString questionName = inputDialog.getMultiLineText(this, "搜索问题", "输入问题名：", "", &ok);
    if(!ok || questionName.isEmpty())
        return;

    //在对应的表中进行查找
    int num = 0; //用于更新Index
    QSqlQuery query(QString("select * from '%1';").arg(tmptable));
    while(query.next())
    {
        num++;
        if(query.value("question").toString() == questionName)
        {
            //找到了
            //清理显示控件
            for(int i = 0; i < 8; i++)
            {
                edits[i]->clear();
                imgs[i]->clear();
            }
            //隐藏多余的选项
            for(int i = 0; i < 4; i++)
            {
                boxs[i]->hide();
            }

            //将问题和选项显示在控件上
            ui->questionEdit->setText(questionName); //设置问题
            int i = 0;
            QString tmp;
            while(i < 8 && "" != (tmp = query.value(QString("option%1").arg(i+1)).toString()))  //设置文本选项
            {
                edits[i]->setText(tmp);
                if(i >= 4)
                {
                    //将多余的按钮显示
                    boxs[i - 4]->show();
                    count = i - 4 + 1;
                }
                i++;
            }
            //设置选项图片
            i = 0;
            while(i < 8)
            {
                QByteArray arry = query.value(QString("imagine"+QString::number(i+1))).toByteArray();
                if(!arry.isEmpty())
                {
                    QImage image;
                    image.loadFromData(arry);
                    if(!image.isNull())
                    {
                        imgs[i]->textCursor().insertImage(image);
                    }
                }
                i++;
            }
            //更新index
            index = num - 1;
            return;
        }
    }
    //搜索失败
    msgBox.setWindowTitle("查找提示");
    msgBox.setText("当前主题中没有该问题，请重新输入！");
    msgBox.exec();
}

//-----------------------导出数据的函数--------------------------------------
//一共分两步
//1.将数据库中的数据读取出来，存放到QList<QList<QVariant>>中
//2.在将QList<QList<QVariant>>转换为QVariant
QVariant SetWindow::datatovariant(QSqlQuery *query_problem, QSqlQuery *query_results, int &row, int sum)
{
    QList<QList<QVariant>> datas; //采用了类模板
    QVariantList vars;

    //++++++++++++++++++++++++++++++++++++第一个步++++++++++++++++++++++++++++++++++

    //*********************访问投票数据的表****************************
    int n = 0; //问题的编号
    while(query_problem->next()) //获取每一个问题,将数据存入datas（类型：QList<QList<QVariant>>）中
    {
        QString str; //存放临时题目和选项
        QList<QVariant> row; //row会获取一行中的每一列
        //---------------------先存放问题题目--------------------------
        str = query_problem->value("question").toString();
        row.append(QString("题目%1").arg(QString::number(n+1))); //将题目标签放入row模板中
        row.append(str); //添加问题
        for(int i = 0; i < 7; i++) //将后面的7个空位置设置为空，否则在Excel表中会出现乱码
        {
            row.append("");
        }
        datas.append(row); //将问题行放入datas模板中
        row.clear();

        //----------------------再存放选项-----------------------------
        row.append("选项");
        for(int i = 1; i <= 8; i++)
        {
            str = query_problem->value(QString("option%1").arg(QString::number(i))).toString();
            row.append(str);
        }
        datas.append(row);
        row.clear();


        //***********************访问存放投票结果的表******************************
        if(query_results->seek(n)) //无论有没有当前问题的投票结果都要统计
        {
            //存在对应问题的投票结果
            int score[8] = {-1, -1, -1, -1, -1, -1, -1, -1};
            int num; //记录每个选项的小计
            //----------------------存放投票结果的小计-----------------------------
            row.append("小计");
            for(int j = 0; j < 8; j++)
            {
                num = query_results->value(QString("option%1").arg(j+1)).toInt();
                if(num < 0)
                {
                    break;
                }
                score[j] = num;
                row.append(num);
            }
            datas.append(row);
            row.clear();

            //----------------------存放投票结果的比例-----------------------------
            row.append("比例");
            for(int j = 0; j < 8 && score[j]>=0; j++)
            {
                row.append(QString::number(score[j]/(sum+0.0), 'g', 2)+"%");
            }
            datas.append(row);
            row.clear();

        }
        else
        {
            //不存在对应问题的投票结果
            //---------------存放投票结果的小计&存放投票结果的比例--------------------
            row.append("小计");
            for(int j = 0; j < 8; j++)
            {
                row.append(0);
            }
            datas.append(row);
            datas.append(row); //因为如果不存在投票结果的话，小计和投票结果都为0
            row.clear();
        }

        //----------------------增加一个空行:每个问题间隔一行---------------------------------------
        for(int j = 0; j < 9; j++)
        {
            row.append("");
        }
        datas.append(row);

        n++;
    }

    //+++++++++++++++++++++++++++++++++++++第二步+++++++++++++++++++++++++++++++++++++++++++++++++++++++
    for(int i = 0 ; i < 5*n; i++)
    {
        vars.append(QVariant(datas[i]));
    }

    row = n;
    return QVariant(vars);

}
//-------------------导出数据--------------------------------
//设置表格中的内容，代码如下
//QString str="通道"+QString::number(i+1);
//cell=worksheet->querySubObject("Cells(int,int)", 1, 3*i+2); //每次设置的是每个单元格
//cell->dynamicCall("SetValue(const QString&)", str);
//也可以通过worksheet->querySubObject("Cells(int, int)", row, col)来给表格设置内容，不过这种方法效率很低，而且慢，下面将介绍一种批量快速添加数据的方法
//QAxObject *range=worksheet->querySubObject("Range(const QString&)","A1:C100");
//这里我们首先需要确定需要添加数据的范围，例如"A1:C100"表示在Excel中，从表格A1开始添加数据，一直添加到表格C100为止（3*100个数据）
//在确定了range大小之后，我们还需要一个QVariant对象来做参数。因此我们需要将模型中的数据保存到QVariant对象中
//一共分两步1.将模型中的数据读取出来，存放到QList<QList<QVariant> >中，在将QList<QList<QVariant> >转换为QVariant
//详细代码见：datatovariant（上一个函数）

void SetWindow::on_exportButton_clicked()
{
    //创建输入对话框:获取要导出的主题名
    bool ok;
    QInputDialog inputDialog;
    inputDialog.setWindowIcon(icon_modify);
    QString theme_name = inputDialog.getText(this, "导出数据", "请输入要导出的主题名：", QLineEdit::Normal, "", &ok);
    if(!ok || theme_name.isEmpty())
        return;

    //检查主题是否存在
    QString tmptablename;
    ok = false;
    QSqlQuery query("select * from tablename;");
    while(query.next())
    {
        if(query.value("themename").toString() == theme_name)
        {
            tmptablename = query.value("number").toString();
            ok = true;
            break;
        }
    }
    if(!ok)
    {
        msgBox.setWindowTitle("导出数据提示");
        msgBox.setText("没有该主题，请重新输入！");
        msgBox.exec();
        return;
    }

    //检查表是否为空
    QString tmpsql = QString("select * from '%1';").arg(tmptablename);
    query.exec(tmpsql);
    if(!query.first())
    {
        msgBox.setWindowTitle("导出数据提示");
        msgBox.setText("当前主题数据为空，无法导出！");
        msgBox.exec();
        return;
    }

    //求当前主题投票人数
    int sum = 0;
    tmpsql = QString("select * from userdata;");
    query.exec(tmpsql);
    while(query.next())
    {
        if(query.value(tmptablename).toInt() == 1)
        {
            sum++;
        }
    }

    //第一步：确定存储路径
    QString fileName = QFileDialog::getSaveFileName(this, "保存", "/data.xlsx", "Excel 文件(*.xls *.xlsx)");


    if(fileName!="")
    {
        //第二步：新建工作簿
        QAxObject *excel = new QAxObject;
        //excel->setControl("Excel.Application");//office连接
        excel->setControl("ket.Application"); //wps连接

        //excel->dynamicCall("SetVisible (bool Visible)","false");//不显示窗体
        //excel->setProperty("DisplayAlerts", false);//不显示任何警告信息。如果为true那么在关闭是会出现类似“文件已修改，是否保存”的提示

        QAxObject *workbooks = excel->querySubObject("WorkBooks");//获取工作簿集合
        workbooks->dynamicCall("Add");//新建一个工作簿

        QAxObject *workbook = excel->querySubObject("ActiveWorkBook");//获取当前工作簿
        QAxObject *worksheet = workbook->querySubObject("Worksheets(int)", 1); //获取当前表


        QSqlQuery query1(QString("select * from '%1';").arg(tmptablename));
        QSqlQuery query2(QString("select * from '%1';").arg(tmptablename+"_Votedata"));

        int row = 0;
        QVariant var = datatovariant(&query1, &query2, row, sum); //调用函数
        QString str = QString("A1:I%0").arg(QString::number(5*row)); //设置存放在excel表中的范围
        QAxObject *range = worksheet->querySubObject("Range(const QString&)",str);

        //批量添加数据
        //range->setProperty("Value",var);  //只支持office的数据保存
        range->setProperty("Value2",var);   //如果想要同时支持office和wps，则需要将参数Value改为Value2

        //批量设置单元个颜色
        for(int i = 1; i <= 5*row; i+=5)
        {
            QAxObject* cell = worksheet->querySubObject("Range(const QString&)", QString("A%0:I%0").arg(i));
            cell->querySubObject("Interior")->setProperty("Color", QColor(0,170,127)); //单元格设置背景颜色
            cell = worksheet->querySubObject("Range(const QString&)", QString("B%0:I%0").arg(i));
            cell->setProperty("MergeCells", true); //合并单元格
            cell->setProperty("HorizontalAlignment", -4131); //设置左对齐
        }

        workbook->dynamicCall("SaveAs(const QString&)",QDir::toNativeSeparators(fileName));//保存至fileName
        workbook->dynamicCall("Close()");//关闭工作簿
        excel->dynamicCall("Quit()");//关闭excel
        delete excel;
        excel = nullptr;

        msgBox.setWindowTitle("导出数据提示");
        msgBox.setText("导出数据成功！");
        msgBox.exec();
    }
}
