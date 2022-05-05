/********************************************************************************
** Form generated from reading UI file 'modifywindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODIFYWINDOW_H
#define UI_MODIFYWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
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

class Ui_ModifyWindow
{
public:
    QWidget *centralwidget;
    QLabel *label_3;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_2;
    QLineEdit *userlineEdit;
    QSpacerItem *verticalSpacer;
    QLineEdit *originalpasswordlineEdit;
    QSpacerItem *verticalSpacer_6;
    QLineEdit *newpasswordlineEdit;
    QSpacerItem *verticalSpacer_7;
    QLineEdit *confirmpasswordlineEdit;
    QSpacerItem *verticalSpacer_3;
    QPushButton *yesButton;
    QSpacerItem *verticalSpacer_4;
    QPushButton *returnButton;
    QSpacerItem *verticalSpacer_5;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *originalButton;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QRadioButton *newButton;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *verticalLayout_4;
    QRadioButton *confirmnewButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ModifyWindow)
    {
        if (ModifyWindow->objectName().isEmpty())
            ModifyWindow->setObjectName(QString::fromUtf8("ModifyWindow"));
        ModifyWindow->resize(1400, 900);
        ModifyWindow->setStyleSheet(QString::fromUtf8("QMainWindow{border-image: url(:/sea.jpg);}"));
        centralwidget = new QWidget(ModifyWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(200, 60, 1001, 91));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(36);
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignCenter);
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(426, 251, 551, 622));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_2 = new QSpacerItem(20, 60, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_2);

        userlineEdit = new QLineEdit(verticalLayoutWidget);
        userlineEdit->setObjectName(QString::fromUtf8("userlineEdit"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setPointSize(18);
        userlineEdit->setFont(font1);

        verticalLayout->addWidget(userlineEdit);

        verticalSpacer = new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        originalpasswordlineEdit = new QLineEdit(verticalLayoutWidget);
        originalpasswordlineEdit->setObjectName(QString::fromUtf8("originalpasswordlineEdit"));
        originalpasswordlineEdit->setFont(font1);

        verticalLayout->addWidget(originalpasswordlineEdit);

        verticalSpacer_6 = new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_6);

        newpasswordlineEdit = new QLineEdit(verticalLayoutWidget);
        newpasswordlineEdit->setObjectName(QString::fromUtf8("newpasswordlineEdit"));
        newpasswordlineEdit->setFont(font1);

        verticalLayout->addWidget(newpasswordlineEdit);

        verticalSpacer_7 = new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_7);

        confirmpasswordlineEdit = new QLineEdit(verticalLayoutWidget);
        confirmpasswordlineEdit->setObjectName(QString::fromUtf8("confirmpasswordlineEdit"));
        confirmpasswordlineEdit->setFont(font1);

        verticalLayout->addWidget(confirmpasswordlineEdit);

        verticalSpacer_3 = new QSpacerItem(20, 50, QSizePolicy::Minimum, QSizePolicy::Fixed);

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

        verticalSpacer_5 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_5);

        verticalLayoutWidget_2 = new QWidget(centralwidget);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(985, 392, 41, 41));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        originalButton = new QRadioButton(verticalLayoutWidget_2);
        originalButton->setObjectName(QString::fromUtf8("originalButton"));

        verticalLayout_2->addWidget(originalButton);

        verticalLayoutWidget_3 = new QWidget(centralwidget);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(985, 472, 41, 41));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        newButton = new QRadioButton(verticalLayoutWidget_3);
        newButton->setObjectName(QString::fromUtf8("newButton"));

        verticalLayout_3->addWidget(newButton);

        verticalLayoutWidget_4 = new QWidget(centralwidget);
        verticalLayoutWidget_4->setObjectName(QString::fromUtf8("verticalLayoutWidget_4"));
        verticalLayoutWidget_4->setGeometry(QRect(985, 555, 41, 41));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget_4);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        confirmnewButton = new QRadioButton(verticalLayoutWidget_4);
        confirmnewButton->setObjectName(QString::fromUtf8("confirmnewButton"));

        verticalLayout_4->addWidget(confirmnewButton);

        ModifyWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ModifyWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1400, 30));
        ModifyWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(ModifyWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        ModifyWindow->setStatusBar(statusbar);

        retranslateUi(ModifyWindow);

        QMetaObject::connectSlotsByName(ModifyWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ModifyWindow)
    {
        ModifyWindow->setWindowTitle(QCoreApplication::translate("ModifyWindow", "\344\277\256\346\224\271\347\225\214\351\235\242", nullptr));
        label_3->setText(QCoreApplication::translate("ModifyWindow", "\346\254\242   \350\277\216   \344\277\256   \346\224\271   \345\257\206   \347\240\201", nullptr));
        userlineEdit->setPlaceholderText(QCoreApplication::translate("ModifyWindow", "\350\276\223\345\205\245\347\224\250\346\210\267\345\220\215", nullptr));
        originalpasswordlineEdit->setText(QString());
        originalpasswordlineEdit->setPlaceholderText(QCoreApplication::translate("ModifyWindow", "\350\276\223\345\205\245\345\216\237\345\247\213\345\257\206\347\240\201", nullptr));
        newpasswordlineEdit->setText(QString());
        newpasswordlineEdit->setPlaceholderText(QCoreApplication::translate("ModifyWindow", "\345\210\233\345\273\272\346\226\260\345\257\206\347\240\201", nullptr));
        confirmpasswordlineEdit->setText(QString());
        confirmpasswordlineEdit->setPlaceholderText(QCoreApplication::translate("ModifyWindow", "\347\241\256\350\256\244\345\257\206\347\240\201", nullptr));
        yesButton->setText(QCoreApplication::translate("ModifyWindow", "\347\241\256\350\256\244\344\277\256\346\224\271", nullptr));
        returnButton->setText(QCoreApplication::translate("ModifyWindow", "\350\277\224\345\233\236\347\231\273\351\231\206\347\225\214\351\235\242", nullptr));
        originalButton->setText(QString());
        newButton->setText(QString());
        confirmnewButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ModifyWindow: public Ui_ModifyWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODIFYWINDOW_H
