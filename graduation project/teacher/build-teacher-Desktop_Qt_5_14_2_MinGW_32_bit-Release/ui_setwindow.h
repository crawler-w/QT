/********************************************************************************
** Form generated from reading UI file 'setwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETWINDOW_H
#define UI_SETWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SetWindow
{
public:
    QWidget *centralwidget;
    QLabel *displaylabel;
    QLabel *label_4;
    QListWidget *displaylistWidget;
    QGroupBox *optionBox1;
    QLabel *label_8;
    QTextEdit *optionEdit5;
    QWidget *verticalLayoutWidget_5;
    QVBoxLayout *Layout5;
    QTextEdit *optionEdit1;
    QTextEdit *optionEdit4;
    QTextEdit *optionEdit3;
    QTextEdit *questionEdit;
    QLabel *label;
    QGroupBox *optionBox4;
    QTextEdit *optionEdit8;
    QLabel *label_10;
    QWidget *verticalLayoutWidget_7;
    QVBoxLayout *Layout8;
    QTextEdit *optionEdit2;
    QLabel *label_9;
    QGroupBox *optionBox2;
    QLabel *label_6;
    QTextEdit *optionEdit6;
    QWidget *verticalLayoutWidget_6;
    QVBoxLayout *Layout6;
    QLabel *label_5;
    QLabel *label_2;
    QLabel *label_11;
    QLabel *label_3;
    QGroupBox *optionBox3;
    QTextEdit *optionEdit7;
    QLabel *label_7;
    QWidget *verticalLayoutWidget_8;
    QVBoxLayout *Layout7;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *Layout1;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *Layout2;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *Layout3;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *Layout4;
    QPushButton *searchButton;
    QGroupBox *operationgroupBox;
    QGroupBox *labelgroupBox;
    QLabel *label3;
    QLabel *label1;
    QLabel *label2;
    QPushButton *optionButton;
    QPushButton *confirmmodifyButton;
    QPushButton *exportButton;
    QPushButton *choicespushButton;
    QPushButton *canceladdButton;
    QPushButton *returnButton;
    QPushButton *upButton;
    QPushButton *themeButton;
    QPushButton *deletethemeButton;
    QPushButton *deletequestionButton;
    QPushButton *confirmButton;
    QPushButton *cancelmodifyButton;
    QPushButton *addButton;
    QPushButton *modifyButton;
    QPushButton *nextButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SetWindow)
    {
        if (SetWindow->objectName().isEmpty())
            SetWindow->setObjectName(QString::fromUtf8("SetWindow"));
        SetWindow->resize(1600, 950);
        SetWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(SetWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        displaylabel = new QLabel(centralwidget);
        displaylabel->setObjectName(QString::fromUtf8("displaylabel"));
        displaylabel->setGeometry(QRect(130, 54, 251, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(18);
        displaylabel->setFont(font);
        displaylabel->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(1010, 305, 91, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font1.setPointSize(14);
        label_4->setFont(font1);
        displaylistWidget = new QListWidget(centralwidget);
        displaylistWidget->setObjectName(QString::fromUtf8("displaylistWidget"));
        displaylistWidget->setGeometry(QRect(130, 154, 251, 451));
        displaylistWidget->setFont(font);
        displaylistWidget->setStyleSheet(QString::fromUtf8(""));
        optionBox1 = new QGroupBox(centralwidget);
        optionBox1->setObjectName(QString::fromUtf8("optionBox1"));
        optionBox1->setGeometry(QRect(420, 391, 571, 100));
        optionBox1->setStyleSheet(QString::fromUtf8(""));
        label_8 = new QLabel(optionBox1);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(10, 34, 91, 31));
        label_8->setFont(font1);
        optionEdit5 = new QTextEdit(optionBox1);
        optionEdit5->setObjectName(QString::fromUtf8("optionEdit5"));
        optionEdit5->setEnabled(false);
        optionEdit5->setGeometry(QRect(280, 4, 280, 91));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font2.setPointSize(12);
        optionEdit5->setFont(font2);
        verticalLayoutWidget_5 = new QWidget(optionBox1);
        verticalLayoutWidget_5->setObjectName(QString::fromUtf8("verticalLayoutWidget_5"));
        verticalLayoutWidget_5->setGeometry(QRect(100, 4, 181, 91));
        Layout5 = new QVBoxLayout(verticalLayoutWidget_5);
        Layout5->setObjectName(QString::fromUtf8("Layout5"));
        Layout5->setContentsMargins(0, 0, 0, 0);
        optionEdit1 = new QTextEdit(centralwidget);
        optionEdit1->setObjectName(QString::fromUtf8("optionEdit1"));
        optionEdit1->setEnabled(false);
        optionEdit1->setGeometry(QRect(700, 155, 280, 91));
        optionEdit1->setFont(font2);
        optionEdit4 = new QTextEdit(centralwidget);
        optionEdit4->setObjectName(QString::fromUtf8("optionEdit4"));
        optionEdit4->setEnabled(false);
        optionEdit4->setGeometry(QRect(1280, 275, 280, 91));
        optionEdit4->setFont(font2);
        optionEdit3 = new QTextEdit(centralwidget);
        optionEdit3->setObjectName(QString::fromUtf8("optionEdit3"));
        optionEdit3->setEnabled(false);
        optionEdit3->setGeometry(QRect(700, 275, 280, 91));
        optionEdit3->setFont(font2);
        questionEdit = new QTextEdit(centralwidget);
        questionEdit->setObjectName(QString::fromUtf8("questionEdit"));
        questionEdit->setEnabled(false);
        questionEdit->setGeometry(QRect(550, 40, 831, 81));
        questionEdit->setFont(font2);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(430, 54, 91, 51));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font3.setPointSize(18);
        label->setFont(font3);
        label->setAlignment(Qt::AlignCenter);
        optionBox4 = new QGroupBox(centralwidget);
        optionBox4->setObjectName(QString::fromUtf8("optionBox4"));
        optionBox4->setGeometry(QRect(1000, 512, 570, 100));
        optionEdit8 = new QTextEdit(optionBox4);
        optionEdit8->setObjectName(QString::fromUtf8("optionEdit8"));
        optionEdit8->setEnabled(false);
        optionEdit8->setGeometry(QRect(280, 4, 280, 91));
        optionEdit8->setFont(font2);
        label_10 = new QLabel(optionBox4);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(10, 35, 91, 31));
        label_10->setFont(font1);
        verticalLayoutWidget_7 = new QWidget(optionBox4);
        verticalLayoutWidget_7->setObjectName(QString::fromUtf8("verticalLayoutWidget_7"));
        verticalLayoutWidget_7->setGeometry(QRect(99, 4, 181, 91));
        Layout8 = new QVBoxLayout(verticalLayoutWidget_7);
        Layout8->setObjectName(QString::fromUtf8("Layout8"));
        Layout8->setContentsMargins(0, 0, 0, 0);
        optionEdit2 = new QTextEdit(centralwidget);
        optionEdit2->setObjectName(QString::fromUtf8("optionEdit2"));
        optionEdit2->setEnabled(false);
        optionEdit2->setGeometry(QRect(1280, 155, 280, 91));
        optionEdit2->setFont(font2);
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(20, 54, 111, 41));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Arial"));
        font4.setPointSize(12);
        label_9->setFont(font4);
        label_9->setAlignment(Qt::AlignCenter);
        optionBox2 = new QGroupBox(centralwidget);
        optionBox2->setObjectName(QString::fromUtf8("optionBox2"));
        optionBox2->setGeometry(QRect(1000, 392, 570, 100));
        label_6 = new QLabel(optionBox2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 34, 91, 31));
        label_6->setFont(font1);
        optionEdit6 = new QTextEdit(optionBox2);
        optionEdit6->setObjectName(QString::fromUtf8("optionEdit6"));
        optionEdit6->setEnabled(false);
        optionEdit6->setGeometry(QRect(280, 3, 280, 91));
        optionEdit6->setFont(font2);
        verticalLayoutWidget_6 = new QWidget(optionBox2);
        verticalLayoutWidget_6->setObjectName(QString::fromUtf8("verticalLayoutWidget_6"));
        verticalLayoutWidget_6->setGeometry(QRect(100, 3, 181, 91));
        Layout6 = new QVBoxLayout(verticalLayoutWidget_6);
        Layout6->setObjectName(QString::fromUtf8("Layout6"));
        Layout6->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(430, 305, 91, 31));
        label_5->setFont(font1);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(430, 185, 91, 31));
        label_2->setFont(font1);
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(20, 157, 111, 41));
        label_11->setFont(font4);
        label_11->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(1010, 185, 91, 31));
        label_3->setFont(font1);
        optionBox3 = new QGroupBox(centralwidget);
        optionBox3->setObjectName(QString::fromUtf8("optionBox3"));
        optionBox3->setGeometry(QRect(420, 512, 570, 100));
        optionEdit7 = new QTextEdit(optionBox3);
        optionEdit7->setObjectName(QString::fromUtf8("optionEdit7"));
        optionEdit7->setEnabled(false);
        optionEdit7->setGeometry(QRect(280, 3, 280, 91));
        optionEdit7->setFont(font2);
        label_7 = new QLabel(optionBox3);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 34, 91, 31));
        label_7->setFont(font1);
        verticalLayoutWidget_8 = new QWidget(optionBox3);
        verticalLayoutWidget_8->setObjectName(QString::fromUtf8("verticalLayoutWidget_8"));
        verticalLayoutWidget_8->setGeometry(QRect(100, 3, 181, 91));
        Layout7 = new QVBoxLayout(verticalLayoutWidget_8);
        Layout7->setObjectName(QString::fromUtf8("Layout7"));
        Layout7->setContentsMargins(0, 0, 0, 0);
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(520, 155, 181, 91));
        Layout1 = new QVBoxLayout(verticalLayoutWidget);
        Layout1->setObjectName(QString::fromUtf8("Layout1"));
        Layout1->setContentsMargins(0, 0, 0, 0);
        verticalLayoutWidget_2 = new QWidget(centralwidget);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(1099, 155, 181, 91));
        Layout2 = new QVBoxLayout(verticalLayoutWidget_2);
        Layout2->setObjectName(QString::fromUtf8("Layout2"));
        Layout2->setContentsMargins(0, 0, 0, 0);
        verticalLayoutWidget_3 = new QWidget(centralwidget);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(520, 275, 181, 91));
        Layout3 = new QVBoxLayout(verticalLayoutWidget_3);
        Layout3->setObjectName(QString::fromUtf8("Layout3"));
        Layout3->setContentsMargins(0, 0, 0, 0);
        verticalLayoutWidget_4 = new QWidget(centralwidget);
        verticalLayoutWidget_4->setObjectName(QString::fromUtf8("verticalLayoutWidget_4"));
        verticalLayoutWidget_4->setGeometry(QRect(1099, 275, 181, 91));
        Layout4 = new QVBoxLayout(verticalLayoutWidget_4);
        Layout4->setObjectName(QString::fromUtf8("Layout4"));
        Layout4->setContentsMargins(0, 0, 0, 0);
        searchButton = new QPushButton(centralwidget);
        searchButton->setObjectName(QString::fromUtf8("searchButton"));
        searchButton->setEnabled(false);
        searchButton->setGeometry(QRect(1399, 46, 161, 61));
        searchButton->setFont(font3);
        searchButton->setStyleSheet(QString::fromUtf8(""));
        operationgroupBox = new QGroupBox(centralwidget);
        operationgroupBox->setObjectName(QString::fromUtf8("operationgroupBox"));
        operationgroupBox->setGeometry(QRect(41, 650, 1541, 261));
        operationgroupBox->setStyleSheet(QString::fromUtf8(""));
        labelgroupBox = new QGroupBox(operationgroupBox);
        labelgroupBox->setObjectName(QString::fromUtf8("labelgroupBox"));
        labelgroupBox->setGeometry(QRect(0, 0, 91, 261));
        label3 = new QLabel(labelgroupBox);
        label3->setObjectName(QString::fromUtf8("label3"));
        label3->setGeometry(QRect(20, 190, 51, 61));
        QFont font5;
        font5.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font5.setPointSize(18);
        label3->setFont(font5);
        label3->setStyleSheet(QString::fromUtf8("border:0px;"));
        label3->setAlignment(Qt::AlignCenter);
        label1 = new QLabel(labelgroupBox);
        label1->setObjectName(QString::fromUtf8("label1"));
        label1->setGeometry(QRect(20, 9, 51, 61));
        label1->setFont(font5);
        label1->setStyleSheet(QString::fromUtf8("border:0px;"));
        label1->setAlignment(Qt::AlignCenter);
        label2 = new QLabel(labelgroupBox);
        label2->setObjectName(QString::fromUtf8("label2"));
        label2->setGeometry(QRect(20, 100, 51, 61));
        label2->setFont(font5);
        label2->setStyleSheet(QString::fromUtf8("border:0px;"));
        label2->setAlignment(Qt::AlignCenter);
        optionButton = new QPushButton(operationgroupBox);
        optionButton->setObjectName(QString::fromUtf8("optionButton"));
        optionButton->setEnabled(false);
        optionButton->setGeometry(QRect(1290, 100, 241, 61));
        optionButton->setFont(font3);
        confirmmodifyButton = new QPushButton(operationgroupBox);
        confirmmodifyButton->setObjectName(QString::fromUtf8("confirmmodifyButton"));
        confirmmodifyButton->setEnabled(false);
        confirmmodifyButton->setGeometry(QRect(780, 100, 200, 61));
        confirmmodifyButton->setFont(font3);
        exportButton = new QPushButton(operationgroupBox);
        exportButton->setObjectName(QString::fromUtf8("exportButton"));
        exportButton->setGeometry(QRect(110, 190, 200, 61));
        exportButton->setFont(font3);
        choicespushButton = new QPushButton(operationgroupBox);
        choicespushButton->setObjectName(QString::fromUtf8("choicespushButton"));
        choicespushButton->setEnabled(false);
        choicespushButton->setGeometry(QRect(1050, 100, 240, 61));
        choicespushButton->setFont(font3);
        canceladdButton = new QPushButton(operationgroupBox);
        canceladdButton->setObjectName(QString::fromUtf8("canceladdButton"));
        canceladdButton->setEnabled(false);
        canceladdButton->setGeometry(QRect(380, 10, 200, 61));
        canceladdButton->setFont(font3);
        returnButton = new QPushButton(operationgroupBox);
        returnButton->setObjectName(QString::fromUtf8("returnButton"));
        returnButton->setGeometry(QRect(1050, 190, 481, 61));
        returnButton->setFont(font3);
        upButton = new QPushButton(operationgroupBox);
        upButton->setObjectName(QString::fromUtf8("upButton"));
        upButton->setEnabled(false);
        upButton->setGeometry(QRect(1050, 10, 240, 61));
        upButton->setFont(font3);
        upButton->setStyleSheet(QString::fromUtf8(""));
        themeButton = new QPushButton(operationgroupBox);
        themeButton->setObjectName(QString::fromUtf8("themeButton"));
        themeButton->setGeometry(QRect(110, 10, 200, 61));
        themeButton->setFont(font3);
        deletethemeButton = new QPushButton(operationgroupBox);
        deletethemeButton->setObjectName(QString::fromUtf8("deletethemeButton"));
        deletethemeButton->setEnabled(false);
        deletethemeButton->setGeometry(QRect(110, 100, 200, 61));
        deletethemeButton->setFont(font3);
        deletequestionButton = new QPushButton(operationgroupBox);
        deletequestionButton->setObjectName(QString::fromUtf8("deletequestionButton"));
        deletequestionButton->setEnabled(false);
        deletequestionButton->setGeometry(QRect(380, 190, 601, 61));
        deletequestionButton->setFont(font3);
        confirmButton = new QPushButton(operationgroupBox);
        confirmButton->setObjectName(QString::fromUtf8("confirmButton"));
        confirmButton->setEnabled(false);
        confirmButton->setGeometry(QRect(780, 10, 200, 61));
        confirmButton->setFont(font3);
        cancelmodifyButton = new QPushButton(operationgroupBox);
        cancelmodifyButton->setObjectName(QString::fromUtf8("cancelmodifyButton"));
        cancelmodifyButton->setEnabled(false);
        cancelmodifyButton->setGeometry(QRect(380, 100, 200, 61));
        cancelmodifyButton->setFont(font3);
        addButton = new QPushButton(operationgroupBox);
        addButton->setObjectName(QString::fromUtf8("addButton"));
        addButton->setEnabled(false);
        addButton->setGeometry(QRect(580, 10, 200, 61));
        addButton->setFont(font3);
        modifyButton = new QPushButton(operationgroupBox);
        modifyButton->setObjectName(QString::fromUtf8("modifyButton"));
        modifyButton->setEnabled(false);
        modifyButton->setGeometry(QRect(580, 100, 200, 61));
        modifyButton->setFont(font3);
        nextButton = new QPushButton(operationgroupBox);
        nextButton->setObjectName(QString::fromUtf8("nextButton"));
        nextButton->setEnabled(false);
        nextButton->setGeometry(QRect(1290, 10, 240, 61));
        nextButton->setFont(font3);
        SetWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(SetWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1600, 30));
        SetWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(SetWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        SetWindow->setStatusBar(statusbar);

        retranslateUi(SetWindow);

        QMetaObject::connectSlotsByName(SetWindow);
    } // setupUi

    void retranslateUi(QMainWindow *SetWindow)
    {
        SetWindow->setWindowTitle(QCoreApplication::translate("SetWindow", "\350\256\276\347\275\256\347\225\214\351\235\242", nullptr));
        displaylabel->setText(QString());
        label_4->setText(QCoreApplication::translate("SetWindow", "\351\200\211\351\241\271\345\233\233", nullptr));
        optionBox1->setTitle(QString());
        label_8->setText(QCoreApplication::translate("SetWindow", "\351\200\211\351\241\271\344\272\224", nullptr));
        optionEdit5->setHtml(QCoreApplication::translate("SetWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'\346\245\267\344\275\223'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'SimSun'; font-size:9pt;\"><br /></p></body></html>", nullptr));
        optionEdit5->setPlaceholderText(QCoreApplication::translate("SetWindow", "\350\257\267\350\276\223\345\205\245\351\200\211\351\241\271", nullptr));
        optionEdit1->setHtml(QCoreApplication::translate("SetWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'\346\245\267\344\275\223'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'SimSun'; font-size:9pt;\"><br /></p></body></html>", nullptr));
        optionEdit1->setPlaceholderText(QCoreApplication::translate("SetWindow", "\350\257\267\350\276\223\345\205\245\351\200\211\351\241\271", nullptr));
        optionEdit4->setHtml(QCoreApplication::translate("SetWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'\346\245\267\344\275\223'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'SimSun'; font-size:9pt;\"><br /></p></body></html>", nullptr));
        optionEdit4->setPlaceholderText(QCoreApplication::translate("SetWindow", "\350\257\267\350\276\223\345\205\245\351\200\211\351\241\271", nullptr));
        optionEdit3->setHtml(QCoreApplication::translate("SetWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'\346\245\267\344\275\223'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'SimSun'; font-size:9pt;\"><br /></p></body></html>", nullptr));
        optionEdit3->setPlaceholderText(QCoreApplication::translate("SetWindow", "\350\257\267\350\276\223\345\205\245\351\200\211\351\241\271", nullptr));
        questionEdit->setHtml(QCoreApplication::translate("SetWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'\346\245\267\344\275\223'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        questionEdit->setPlaceholderText(QCoreApplication::translate("SetWindow", "\350\257\267\350\276\223\345\205\245\351\227\256\351\242\230", nullptr));
        label->setText(QCoreApplication::translate("SetWindow", "\351\227\256\351\242\230", nullptr));
        optionBox4->setTitle(QString());
        optionEdit8->setHtml(QCoreApplication::translate("SetWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'\346\245\267\344\275\223'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'SimSun'; font-size:9pt;\"><br /></p></body></html>", nullptr));
        optionEdit8->setPlaceholderText(QCoreApplication::translate("SetWindow", "\350\257\267\350\276\223\345\205\245\351\200\211\351\241\271", nullptr));
        label_10->setText(QCoreApplication::translate("SetWindow", "\351\200\211\351\241\271\345\205\253", nullptr));
        optionEdit2->setHtml(QCoreApplication::translate("SetWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'\346\245\267\344\275\223'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'SimSun'; font-size:9pt;\"><br /></p></body></html>", nullptr));
        optionEdit2->setPlaceholderText(QCoreApplication::translate("SetWindow", "\350\257\267\350\276\223\345\205\245\351\200\211\351\241\271", nullptr));
        label_9->setText(QCoreApplication::translate("SetWindow", "\345\275\223\345\211\215\344\270\273\351\242\230", nullptr));
        optionBox2->setTitle(QString());
        label_6->setText(QCoreApplication::translate("SetWindow", "\351\200\211\351\241\271\345\205\255", nullptr));
        optionEdit6->setHtml(QCoreApplication::translate("SetWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'\346\245\267\344\275\223'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'SimSun'; font-size:9pt;\"><br /></p></body></html>", nullptr));
        optionEdit6->setPlaceholderText(QCoreApplication::translate("SetWindow", "\350\257\267\350\276\223\345\205\245\351\200\211\351\241\271", nullptr));
        label_5->setText(QCoreApplication::translate("SetWindow", "\351\200\211\351\241\271\344\270\211", nullptr));
        label_2->setText(QCoreApplication::translate("SetWindow", "\351\200\211\351\241\271\344\270\200", nullptr));
        label_11->setText(QCoreApplication::translate("SetWindow", "\347\216\260\346\234\211\344\270\273\351\242\230", nullptr));
        label_3->setText(QCoreApplication::translate("SetWindow", "\351\200\211\351\241\271\344\272\214", nullptr));
        optionBox3->setTitle(QString());
        optionEdit7->setHtml(QCoreApplication::translate("SetWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'\346\245\267\344\275\223'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'SimSun'; font-size:9pt;\"><br /></p></body></html>", nullptr));
        optionEdit7->setPlaceholderText(QCoreApplication::translate("SetWindow", "\350\257\267\350\276\223\345\205\245\351\200\211\351\241\271", nullptr));
        label_7->setText(QCoreApplication::translate("SetWindow", "\351\200\211\351\241\271\344\270\203", nullptr));
        searchButton->setText(QCoreApplication::translate("SetWindow", "\346\220\234\347\264\242", nullptr));
        operationgroupBox->setTitle(QString());
        labelgroupBox->setTitle(QString());
        label3->setText(QCoreApplication::translate("SetWindow", "\345\214\272", nullptr));
        label1->setText(QCoreApplication::translate("SetWindow", "\346\223\215", nullptr));
        label2->setText(QCoreApplication::translate("SetWindow", "\344\275\234", nullptr));
        optionButton->setText(QCoreApplication::translate("SetWindow", "\345\242\236\345\212\240\351\200\211\351\241\271", nullptr));
        confirmmodifyButton->setText(QCoreApplication::translate("SetWindow", "\347\241\256\345\256\232\344\277\256\346\224\271", nullptr));
        exportButton->setText(QCoreApplication::translate("SetWindow", "\345\257\274\345\207\272\346\225\260\346\215\256", nullptr));
        choicespushButton->setText(QCoreApplication::translate("SetWindow", "\345\215\225\351\200\211", nullptr));
        canceladdButton->setText(QCoreApplication::translate("SetWindow", "\345\217\226\346\266\210\346\267\273\345\212\240", nullptr));
        returnButton->setText(QCoreApplication::translate("SetWindow", "\350\277\224\345\233\236", nullptr));
        upButton->setText(QCoreApplication::translate("SetWindow", "\344\270\212\344\270\200\344\270\252", nullptr));
        themeButton->setText(QCoreApplication::translate("SetWindow", "\345\242\236\345\212\240\344\270\273\351\242\230", nullptr));
        deletethemeButton->setText(QCoreApplication::translate("SetWindow", "\345\210\240\351\231\244\344\270\273\351\242\230", nullptr));
        deletequestionButton->setText(QCoreApplication::translate("SetWindow", "\345\210\240\351\231\244\351\227\256\351\242\230", nullptr));
        confirmButton->setText(QCoreApplication::translate("SetWindow", "\347\241\256\345\256\232\346\267\273\345\212\240", nullptr));
        cancelmodifyButton->setText(QCoreApplication::translate("SetWindow", "\345\217\226\346\266\210\344\277\256\346\224\271", nullptr));
        addButton->setText(QCoreApplication::translate("SetWindow", "\346\267\273\345\212\240\351\227\256\351\242\230", nullptr));
        modifyButton->setText(QCoreApplication::translate("SetWindow", "\344\277\256\346\224\271\351\227\256\351\242\230", nullptr));
        nextButton->setText(QCoreApplication::translate("SetWindow", "\344\270\213\344\270\200\344\270\252", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SetWindow: public Ui_SetWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETWINDOW_H
