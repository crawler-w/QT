#ifndef RESULTWINDOW_H
#define RESULTWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>


namespace Ui {
class ResultWindow;
}

class ResultWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ResultWindow(QWidget *parent = nullptr);
    ~ResultWindow();

private slots:
    void on_votelistWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_returnButton_clicked();

    void on_returnloginButton_clicked();

private:
    Ui::ResultWindow *ui;
    QStringList options;
    QIcon icon_window;
};

#endif // RESULTWINDOW_H
