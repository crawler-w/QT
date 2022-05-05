#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H
#include <QMainWindow>
#include <QSqlDatabase>
#include <QMessageBox>
QT_BEGIN_NAMESPACE
namespace Ui { class LoginWindow; }
QT_END_NAMESPACE

class LoginWindow : public QMainWindow
{
    Q_OBJECT

public:
    LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();

private slots:
    void on_voteButton_clicked();

    void on_setButton_clicked();

    void on_registerButton_clicked();

    void on_modifyButton_clicked();

    void on_passwordButton_clicked(bool checked);

signals:
    void send_userdata(QString m_user, QString m_password);

private:
    Ui::LoginWindow *ui;
    QSqlDatabase db;
    QMessageBox msgBox;
    QIcon icon_window;
    QIcon icon_msgBox;

};
#endif // LOGINWINDOW_H
