/********************************************************************************
** Form generated from reading UI file 'resultwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESULTWINDOW_H
#define UI_RESULTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ResultWindow
{
public:
    QWidget *centralwidget;
    QPushButton *returnButton;
    QListWidget *votelistWidget;
    QLabel *label_3;
    QPushButton *returnloginButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ResultWindow)
    {
        if (ResultWindow->objectName().isEmpty())
            ResultWindow->setObjectName(QString::fromUtf8("ResultWindow"));
        ResultWindow->resize(1200, 900);
        ResultWindow->setStyleSheet(QString::fromUtf8("QMainwindow{background-color: rgb(170, 255, 255);}"));
        centralwidget = new QWidget(ResultWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        returnButton = new QPushButton(centralwidget);
        returnButton->setObjectName(QString::fromUtf8("returnButton"));
        returnButton->setGeometry(QRect(230, 800, 511, 61));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(16);
        returnButton->setFont(font);
        votelistWidget = new QListWidget(centralwidget);
        votelistWidget->setObjectName(QString::fromUtf8("votelistWidget"));
        votelistWidget->setGeometry(QRect(0, 51, 230, 811));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setPointSize(16);
        votelistWidget->setFont(font1);
        votelistWidget->setStyleSheet(QString::fromUtf8(""));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(0, 0, 230, 52));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font2.setPointSize(26);
        label_3->setFont(font2);
        label_3->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"background-color: rgb(85, 170, 127);"));
        label_3->setAlignment(Qt::AlignCenter);
        returnloginButton = new QPushButton(centralwidget);
        returnloginButton->setObjectName(QString::fromUtf8("returnloginButton"));
        returnloginButton->setGeometry(QRect(740, 800, 461, 61));
        returnloginButton->setFont(font);
        ResultWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ResultWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1200, 30));
        ResultWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(ResultWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        ResultWindow->setStatusBar(statusbar);

        retranslateUi(ResultWindow);

        QMetaObject::connectSlotsByName(ResultWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ResultWindow)
    {
        ResultWindow->setWindowTitle(QCoreApplication::translate("ResultWindow", "\346\212\225\347\245\250\347\273\223\346\236\234\347\225\214\351\235\242", nullptr));
        returnButton->setText(QCoreApplication::translate("ResultWindow", "\350\277\224\345\233\236\346\212\225\347\245\250\347\225\214\351\235\242", nullptr));
        label_3->setText(QCoreApplication::translate("ResultWindow", "\344\270\273\351\242\230\345\220\215", nullptr));
        returnloginButton->setText(QCoreApplication::translate("ResultWindow", "\350\277\224\345\233\236\347\231\273\351\231\206\347\225\214\351\235\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ResultWindow: public Ui_ResultWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESULTWINDOW_H
