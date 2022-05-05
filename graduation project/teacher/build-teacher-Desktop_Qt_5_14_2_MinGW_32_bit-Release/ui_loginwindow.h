/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWindow
{
public:
    QWidget *centralwidget;
    QLabel *label_4;
    QGroupBox *groupBox;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_7;
    QVBoxLayout *verticalLayout_6;
    QSpacerItem *verticalSpacer_17;
    QLabel *logolabel;
    QSpacerItem *verticalSpacer;
    QLineEdit *userlineEdit;
    QSpacerItem *verticalSpacer_10;
    QLineEdit *passwordlineEdit;
    QSpacerItem *verticalSpacer_11;
    QPushButton *voteButton;
    QSpacerItem *verticalSpacer_12;
    QPushButton *setButton;
    QSpacerItem *verticalSpacer_14;
    QHBoxLayout *horizontalLayout;
    QPushButton *registerButton;
    QPushButton *modifyButton;
    QSpacerItem *verticalSpacer_13;
    QRadioButton *passwordButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName(QString::fromUtf8("LoginWindow"));
        LoginWindow->resize(1400, 900);
        centralwidget = new QWidget(LoginWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(250, 20, 941, 71));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(36);
        label_4->setFont(font);
        label_4->setStyleSheet(QString::fromUtf8(""));
        label_4->setAlignment(Qt::AlignCenter);
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(386, 130, 631, 711));
        groupBox->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        verticalLayoutWidget_2 = new QWidget(groupBox);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(56, 10, 521, 681));
        verticalLayout_7 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalSpacer_17 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_6->addItem(verticalSpacer_17);

        logolabel = new QLabel(verticalLayoutWidget_2);
        logolabel->setObjectName(QString::fromUtf8("logolabel"));
        logolabel->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(logolabel);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_6->addItem(verticalSpacer);

        userlineEdit = new QLineEdit(verticalLayoutWidget_2);
        userlineEdit->setObjectName(QString::fromUtf8("userlineEdit"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setPointSize(22);
        userlineEdit->setFont(font1);

        verticalLayout_6->addWidget(userlineEdit);

        verticalSpacer_10 = new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_6->addItem(verticalSpacer_10);

        passwordlineEdit = new QLineEdit(verticalLayoutWidget_2);
        passwordlineEdit->setObjectName(QString::fromUtf8("passwordlineEdit"));
        passwordlineEdit->setFont(font1);
        passwordlineEdit->setEchoMode(QLineEdit::Normal);

        verticalLayout_6->addWidget(passwordlineEdit);

        verticalSpacer_11 = new QSpacerItem(20, 60, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_6->addItem(verticalSpacer_11);

        voteButton = new QPushButton(verticalLayoutWidget_2);
        voteButton->setObjectName(QString::fromUtf8("voteButton"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font2.setPointSize(18);
        voteButton->setFont(font2);

        verticalLayout_6->addWidget(voteButton);

        verticalSpacer_12 = new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_6->addItem(verticalSpacer_12);

        setButton = new QPushButton(verticalLayoutWidget_2);
        setButton->setObjectName(QString::fromUtf8("setButton"));
        setButton->setFont(font2);

        verticalLayout_6->addWidget(setButton);

        verticalSpacer_14 = new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_6->addItem(verticalSpacer_14);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetFixedSize);
        horizontalLayout->setContentsMargins(0, -1, -1, -1);
        registerButton = new QPushButton(verticalLayoutWidget_2);
        registerButton->setObjectName(QString::fromUtf8("registerButton"));
        registerButton->setFont(font2);

        horizontalLayout->addWidget(registerButton);

        modifyButton = new QPushButton(verticalLayoutWidget_2);
        modifyButton->setObjectName(QString::fromUtf8("modifyButton"));
        modifyButton->setFont(font2);

        horizontalLayout->addWidget(modifyButton);


        verticalLayout_6->addLayout(horizontalLayout);

        verticalSpacer_13 = new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_6->addItem(verticalSpacer_13);


        verticalLayout_7->addLayout(verticalLayout_6);

        passwordButton = new QRadioButton(groupBox);
        passwordButton->setObjectName(QString::fromUtf8("passwordButton"));
        passwordButton->setGeometry(QRect(586, 374, 21, 22));
        LoginWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(LoginWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1400, 30));
        LoginWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(LoginWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        LoginWindow->setStatusBar(statusbar);

        retranslateUi(LoginWindow);

        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QMainWindow *LoginWindow)
    {
        LoginWindow->setWindowTitle(QCoreApplication::translate("LoginWindow", "\347\231\273\351\231\206\347\225\214\351\235\242", nullptr));
        label_4->setText(QCoreApplication::translate("LoginWindow", "\346\254\242\350\277\216\346\235\245\345\210\260\345\225\206\346\264\233\345\255\246\351\231\242\346\212\225\347\245\250\347\263\273\347\273\237", nullptr));
        groupBox->setTitle(QString());
        logolabel->setText(QString());
        userlineEdit->setPlaceholderText(QCoreApplication::translate("LoginWindow", "\350\276\223\345\205\245\347\224\250\346\210\267\345\220\215", nullptr));
        passwordlineEdit->setText(QString());
        passwordlineEdit->setPlaceholderText(QCoreApplication::translate("LoginWindow", "\350\276\223\345\205\245\345\257\206\347\240\201", nullptr));
        voteButton->setText(QCoreApplication::translate("LoginWindow", "\347\231\273\351\231\206", nullptr));
        setButton->setText(QCoreApplication::translate("LoginWindow", "\350\256\276\347\275\256\346\212\225\347\245\250", nullptr));
        registerButton->setText(QCoreApplication::translate("LoginWindow", "\346\263\250\345\206\214", nullptr));
        modifyButton->setText(QCoreApplication::translate("LoginWindow", "\344\277\256\346\224\271\345\257\206\347\240\201", nullptr));
        passwordButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
