/********************************************************************************
** Form generated from reading UI file 'registerwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERWINDOW_H
#define UI_REGISTERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
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

class Ui_RegisterWindow
{
public:
    QWidget *centralwidget;
    QLabel *label_3;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_2;
    QLineEdit *userlineEdit;
    QSpacerItem *verticalSpacer;
    QLineEdit *passwordlineEdit;
    QSpacerItem *verticalSpacer_8;
    QLineEdit *confirmpasswordlineEdit;
    QSpacerItem *verticalSpacer_6;
    QLineEdit *telephonelineEdit;
    QSpacerItem *verticalSpacer_7;
    QHBoxLayout *horizontalLayout;
    QLineEdit *codelineEdit;
    QPushButton *codeButton;
    QSpacerItem *verticalSpacer_3;
    QPushButton *yesButton;
    QSpacerItem *verticalSpacer_4;
    QPushButton *returnButton;
    QSpacerItem *verticalSpacer_5;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *passwordButton;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QRadioButton *confirmpasswordButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *RegisterWindow)
    {
        if (RegisterWindow->objectName().isEmpty())
            RegisterWindow->setObjectName(QString::fromUtf8("RegisterWindow"));
        RegisterWindow->resize(1400, 900);
        RegisterWindow->setStyleSheet(QString::fromUtf8("QMainWindow{border-image: url(:/sea.jpg);}"));
        centralwidget = new QWidget(RegisterWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(270, 60, 841, 91));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(36);
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignCenter);
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(416, 280, 551, 631));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_2 = new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_2);

        userlineEdit = new QLineEdit(verticalLayoutWidget);
        userlineEdit->setObjectName(QString::fromUtf8("userlineEdit"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setPointSize(18);
        userlineEdit->setFont(font1);

        verticalLayout->addWidget(userlineEdit);

        verticalSpacer = new QSpacerItem(20, 15, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        passwordlineEdit = new QLineEdit(verticalLayoutWidget);
        passwordlineEdit->setObjectName(QString::fromUtf8("passwordlineEdit"));
        passwordlineEdit->setFont(font1);

        verticalLayout->addWidget(passwordlineEdit);

        verticalSpacer_8 = new QSpacerItem(20, 15, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_8);

        confirmpasswordlineEdit = new QLineEdit(verticalLayoutWidget);
        confirmpasswordlineEdit->setObjectName(QString::fromUtf8("confirmpasswordlineEdit"));
        confirmpasswordlineEdit->setFont(font1);

        verticalLayout->addWidget(confirmpasswordlineEdit);

        verticalSpacer_6 = new QSpacerItem(20, 15, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_6);

        telephonelineEdit = new QLineEdit(verticalLayoutWidget);
        telephonelineEdit->setObjectName(QString::fromUtf8("telephonelineEdit"));
        telephonelineEdit->setFont(font1);

        verticalLayout->addWidget(telephonelineEdit);

        verticalSpacer_7 = new QSpacerItem(20, 15, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_7);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetMinAndMaxSize);
        horizontalLayout->setContentsMargins(0, -1, -1, -1);
        codelineEdit = new QLineEdit(verticalLayoutWidget);
        codelineEdit->setObjectName(QString::fromUtf8("codelineEdit"));
        codelineEdit->setFont(font1);

        horizontalLayout->addWidget(codelineEdit);

        codeButton = new QPushButton(verticalLayoutWidget);
        codeButton->setObjectName(QString::fromUtf8("codeButton"));
        codeButton->setFont(font1);

        horizontalLayout->addWidget(codeButton);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_3);

        yesButton = new QPushButton(verticalLayoutWidget);
        yesButton->setObjectName(QString::fromUtf8("yesButton"));
        yesButton->setFont(font1);

        verticalLayout->addWidget(yesButton);

        verticalSpacer_4 = new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_4);

        returnButton = new QPushButton(verticalLayoutWidget);
        returnButton->setObjectName(QString::fromUtf8("returnButton"));
        returnButton->setFont(font1);

        verticalLayout->addWidget(returnButton);

        verticalSpacer_5 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_5);

        verticalLayoutWidget_2 = new QWidget(centralwidget);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(973, 385, 31, 31));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        passwordButton = new QRadioButton(verticalLayoutWidget_2);
        passwordButton->setObjectName(QString::fromUtf8("passwordButton"));

        verticalLayout_2->addWidget(passwordButton);

        verticalLayoutWidget_3 = new QWidget(centralwidget);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(973, 449, 31, 31));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        confirmpasswordButton = new QRadioButton(verticalLayoutWidget_3);
        confirmpasswordButton->setObjectName(QString::fromUtf8("confirmpasswordButton"));

        verticalLayout_3->addWidget(confirmpasswordButton);

        RegisterWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(RegisterWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1400, 30));
        RegisterWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(RegisterWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        RegisterWindow->setStatusBar(statusbar);

        retranslateUi(RegisterWindow);

        QMetaObject::connectSlotsByName(RegisterWindow);
    } // setupUi

    void retranslateUi(QMainWindow *RegisterWindow)
    {
        RegisterWindow->setWindowTitle(QCoreApplication::translate("RegisterWindow", "\346\263\250\345\206\214\347\225\214\351\235\242", nullptr));
        label_3->setText(QCoreApplication::translate("RegisterWindow", "\346\254\242     \350\277\216     \346\263\250     \345\206\214", nullptr));
        userlineEdit->setPlaceholderText(QCoreApplication::translate("RegisterWindow", "\345\210\233\345\273\272\347\224\250\346\210\267\345\220\215", nullptr));
        passwordlineEdit->setText(QString());
        passwordlineEdit->setPlaceholderText(QCoreApplication::translate("RegisterWindow", "\345\210\233\345\273\272\345\257\206\347\240\201", nullptr));
        confirmpasswordlineEdit->setText(QString());
        confirmpasswordlineEdit->setPlaceholderText(QCoreApplication::translate("RegisterWindow", "\347\241\256\350\256\244\345\257\206\347\240\201", nullptr));
        telephonelineEdit->setText(QString());
        telephonelineEdit->setPlaceholderText(QCoreApplication::translate("RegisterWindow", "\350\276\223\345\205\245\346\211\213\346\234\272\345\217\267", nullptr));
        codelineEdit->setText(QString());
        codelineEdit->setPlaceholderText(QCoreApplication::translate("RegisterWindow", "\350\276\223\345\205\245\351\252\214\350\257\201\347\240\201", nullptr));
        codeButton->setText(QCoreApplication::translate("RegisterWindow", "\345\217\221\351\200\201\351\252\214\350\257\201\347\240\201", nullptr));
        yesButton->setText(QCoreApplication::translate("RegisterWindow", "\346\217\220\344\272\244\346\263\250\345\206\214", nullptr));
        returnButton->setText(QCoreApplication::translate("RegisterWindow", "\350\277\224\345\233\236\347\231\273\351\231\206\351\241\265\351\235\242", nullptr));
        passwordButton->setText(QString());
        confirmpasswordButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class RegisterWindow: public Ui_RegisterWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERWINDOW_H
