/********************************************************************************
** Form generated from reading UI file 'votepage.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VOTEPAGE_H
#define UI_VOTEPAGE_H

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

class Ui_VotePage
{
public:
    QWidget *centralwidget;
    QListWidget *displaylistWidget;
    QLabel *label;
    QLabel *label_3;
    QPushButton *submitButton;
    QPushButton *lookButton;
    QPushButton *returnButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *VotePage)
    {
        if (VotePage->objectName().isEmpty())
            VotePage->setObjectName(QString::fromUtf8("VotePage"));
        VotePage->resize(1200, 900);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(6);
        sizePolicy.setHeightForWidth(VotePage->sizePolicy().hasHeightForWidth());
        VotePage->setSizePolicy(sizePolicy);
        VotePage->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(VotePage);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        displaylistWidget = new QListWidget(centralwidget);
        displaylistWidget->setObjectName(QString::fromUtf8("displaylistWidget"));
        displaylistWidget->setGeometry(QRect(0, 52, 221, 811));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(16);
        displaylistWidget->setFont(font);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(220, 0, 981, 52));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font1.setPointSize(14);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        label->setFont(font1);
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 85, 127);"));
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(0, 0, 221, 52));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font2.setPointSize(26);
        label_3->setFont(font2);
        label_3->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 85, 127);"));
        label_3->setAlignment(Qt::AlignCenter);
        submitButton = new QPushButton(centralwidget);
        submitButton->setObjectName(QString::fromUtf8("submitButton"));
        submitButton->setEnabled(false);
        submitButton->setGeometry(QRect(220, 783, 321, 79));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(submitButton->sizePolicy().hasHeightForWidth());
        submitButton->setSizePolicy(sizePolicy1);
        QFont font3;
        font3.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font3.setPointSize(18);
        submitButton->setFont(font3);
        lookButton = new QPushButton(centralwidget);
        lookButton->setObjectName(QString::fromUtf8("lookButton"));
        lookButton->setEnabled(true);
        lookButton->setGeometry(QRect(540, 783, 330, 79));
        sizePolicy1.setHeightForWidth(lookButton->sizePolicy().hasHeightForWidth());
        lookButton->setSizePolicy(sizePolicy1);
        lookButton->setFont(font3);
        returnButton = new QPushButton(centralwidget);
        returnButton->setObjectName(QString::fromUtf8("returnButton"));
        returnButton->setEnabled(true);
        returnButton->setGeometry(QRect(870, 783, 330, 79));
        sizePolicy1.setHeightForWidth(returnButton->sizePolicy().hasHeightForWidth());
        returnButton->setSizePolicy(sizePolicy1);
        returnButton->setFont(font3);
        VotePage->setCentralWidget(centralwidget);
        menubar = new QMenuBar(VotePage);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1200, 30));
        VotePage->setMenuBar(menubar);
        statusbar = new QStatusBar(VotePage);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        VotePage->setStatusBar(statusbar);

        retranslateUi(VotePage);

        QMetaObject::connectSlotsByName(VotePage);
    } // setupUi

    void retranslateUi(QMainWindow *VotePage)
    {
        VotePage->setWindowTitle(QCoreApplication::translate("VotePage", "\346\212\225\347\245\250\347\225\214\351\235\242", nullptr));
        label->setText(QCoreApplication::translate("VotePage", "\346\270\251\351\246\250\346\217\220\347\244\272:\345\246\202\346\236\234\344\275\240\345\210\207\346\215\242\345\210\260\344\270\213\344\270\200\344\270\252\346\212\225\347\245\250\344\270\273\351\242\230\357\274\214\346\202\250\345\234\250\347\233\256\345\211\215\344\270\273\351\242\230\344\270\212\347\232\204\344\275\234\347\255\224\350\256\260\345\275\225\345\260\206\344\270\215\344\277\235\345\255\230", nullptr));
        label_3->setText(QCoreApplication::translate("VotePage", "\344\270\273\351\242\230\345\220\215", nullptr));
        submitButton->setText(QCoreApplication::translate("VotePage", "\346\217\220\344\272\244", nullptr));
        lookButton->setText(QCoreApplication::translate("VotePage", "\346\212\225\347\245\250\347\273\223\346\236\234", nullptr));
        returnButton->setText(QCoreApplication::translate("VotePage", "\350\277\224\345\233\236\347\231\273\351\231\206\347\225\214\351\235\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class VotePage: public Ui_VotePage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VOTEPAGE_H
