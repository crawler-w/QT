#ifndef MODIFYWINDOW_H
#define MODIFYWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
namespace Ui {
class ModifyWindow;
}

class ModifyWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ModifyWindow(QWidget *parent = nullptr);
    ~ModifyWindow();

private slots:
    void on_returnButton_clicked();

    void on_yesButton_clicked();

    void on_originalButton_clicked(bool checked);

    void on_newButton_clicked(bool checked);

    void on_confirmnewButton_clicked(bool checked);

private:
    Ui::ModifyWindow *ui;
    QMessageBox msgBox;
    QIcon icon_window;
    QIcon icon_msgBox;
};

#endif // MODIFYWINDOW_H
