#ifndef VOTEPAGE_H
#define VOTEPAGE_H

#include <QMainWindow>
#include <QMessageBox>
#include <QListWidgetItem>
#include <QStackedWidget>

namespace Ui {
class VotePage;
}

class VotePage : public QMainWindow
{
    Q_OBJECT

public:
    explicit VotePage(QWidget *parent = nullptr);

    ~VotePage();

private slots:
    void on_displaylistWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_submitButton_clicked();

    void on_returnButton_clicked();

    void on_lookButton_clicked();

public slots:

    void receive_userdata(QString m_user, QString m_password);

private:
    Ui::VotePage *ui;
    QMessageBox msgBox;
    QIcon icon_window;
    QIcon icon_msgBox;
    int isopen; //当前主题中是否有问题
    QString tmptable;//当前主题对应的存放问题的表
    QString tmpthemename; //当前主题名，切换主题时判断是否切换了主题，来进行跟新
    QString user; //记录当前访问者的用户名
    QString password;//记录当前访问者的密码


    QStackedWidget *stackedWidget; //创建一个栈窗口控件,存放多个问题

};
#endif // VOTEPAGE_H
