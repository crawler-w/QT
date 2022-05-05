#ifndef SETWINDOW_H
#define SETWINDOW_H

#include <QMainWindow>
#include <QGroupBox>
#include <QListWidgetItem>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QMimeData>
#include <QFileInfo>
#include <QImageReader>
#include <QUrl>
#include <QImage>
#include <QSqlQuery>
#include <QTextEdit>
namespace Ui {
class SetWindow;
}


class TextEdit : public QTextEdit
{
public:
    bool canInsertFromMimeData(const QMimeData* source) const
    {
        return source->hasImage() || source->hasUrls() ||
            QTextEdit::canInsertFromMimeData(source);
    }

    void insertFromMimeData(const QMimeData* source)
    {
        if (source->hasImage())
        {
            static int i = 1;
            QUrl url(QString("dropped_image_%1").arg(i++));
            dropImage(url, qvariant_cast<QImage>(source->imageData()));
        }
        else if (source->hasUrls())
        {
            foreach (QUrl url, source->urls())
            {
                QFileInfo info(url.toLocalFile());
                if (QImageReader::supportedImageFormats().contains(info.suffix().toLower().toLatin1()))
                    dropImage(url, QImage(info.filePath()));
                else
                    dropTextFile(url);
            }
        }
        else
        {
            QTextEdit::insertFromMimeData(source);
        }
    }

private:
    void dropImage(const QUrl& url, const QImage& image)
    {
        if (!image.isNull())
        {
            document()->addResource(QTextDocument::ImageResource, url, image);
            textCursor().insertImage(url.toString());
        }
    }

    void dropTextFile(const QUrl& url)
    {
        QFile file(url.toLocalFile());
        if (file.open(QIODevice::ReadOnly | QIODevice::Text))
            textCursor().insertText(file.readAll());
    }
};

class SetWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SetWindow(QWidget *parent = nullptr);

    ~SetWindow();

private slots:
    void on_confirmButton_clicked();

    void on_optionButton_clicked();

    void on_returnButton_clicked();

    void on_deletethemeButton_clicked();

    void on_themeButton_clicked();

    void on_displaylistWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_modifyButton_clicked();

    void on_upButton_clicked();

    void on_nextButton_clicked();

    void on_addButton_clicked();

    void on_confirmmodifyButton_clicked();

    void on_deletequestionButton_clicked();

    void on_choicespushButton_clicked();

    void on_canceladdButton_clicked();

    void on_cancelmodifyButton_clicked();

    void on_searchButton_clicked();

    void on_exportButton_clicked();

private:
    QVariant datatovariant(QSqlQuery *query_problem, QSqlQuery *query_results, int &row, int sum); //导出数据的函数，详细见源程序文件

private:
    Ui::SetWindow *ui;
    QMessageBox msgBox;
    QIcon icon_window;
    QIcon icon_msgBox;
    QIcon icon_modify;
    QTextEdit* edits[8]; //存储所有选项
    QGroupBox* boxs[4]; //存储后三个选项
    int count; //用于控制显示多余的选项
    int index; //记录当前表的索引
    bool ischoice; //单选还是多选（false代表单选，true代表多选）
    QString tmptable;//当前主题对应的存放问题的表

    QStringList tables;
    int shownum;

    QVBoxLayout* layouts[8];
    TextEdit* imgs[8];

};

#endif // SETWINDOW_H
