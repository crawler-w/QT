#ifndef REGISTERWINDOW_H
#define REGISTERWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QNetworkAccessManager>
#include <QTimer>
namespace Ui {
class RegisterWindow;
}

class RegisterWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit RegisterWindow(QWidget *parent = nullptr);
    ~RegisterWindow();

private slots:
    void on_yesButton_clicked();

    void on_returnButton_clicked();

    void on_passwordButton_clicked(bool checked);


    void on_confirmpasswordButton_clicked(bool checked);

    // 单发短信：给用户发短信验证码、短信通知，营销短息（内容长度不超过450字节）
    void singleMessage(QString mobile, QString content);

    void on_codeButton_clicked();

    void calcount(); //用于定时器计数的槽函数

private:
    Ui::RegisterWindow *ui;
    QMessageBox msgBox;
    QIcon icon_window;
    QIcon icon_msgBox;

    QTimer *timer; //定时器指针
    static int count; //定时器的时间

    QNetworkAccessManager manager; //发送网络请求和接收响应
    static QString sdkAppId; //云信使平台用户名
    static QString sdkAppKey; //用户对应的接口密码
    QString code; //发送的验证码
    QStringList telephonelist; //存放核验电话号码

};


#endif // REGISTERWINDOW_H
