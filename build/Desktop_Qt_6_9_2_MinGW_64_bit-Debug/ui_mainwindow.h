/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout_5;
    QLabel *label_password;
    QSpacerItem *verticalSpacer_6;
    QSpacerItem *verticalSpacer_4;
    QLabel *label_nickname;
    QLabel *label_logIn;
    QLineEdit *lineEdit_2;
    QLineEdit *enter_nickname;
    QPushButton *buttonLogIn;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_5;
    QLabel *titulo;
    QSpacerItem *verticalSpacer_8;
    QLabel *label_registrarse;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(901, 657);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName("gridLayout_5");
        label_password = new QLabel(centralwidget);
        label_password->setObjectName("label_password");
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        label_password->setFont(font);

        gridLayout_5->addWidget(label_password, 6, 0, 1, 1);

        verticalSpacer_6 = new QSpacerItem(20, 100, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_5->addItem(verticalSpacer_6, 5, 0, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 250, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_5->addItem(verticalSpacer_4, 1, 0, 1, 1);

        label_nickname = new QLabel(centralwidget);
        label_nickname->setObjectName("label_nickname");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_nickname->sizePolicy().hasHeightForWidth());
        label_nickname->setSizePolicy(sizePolicy);
        label_nickname->setFont(font);

        gridLayout_5->addWidget(label_nickname, 3, 0, 1, 1);

        label_logIn = new QLabel(centralwidget);
        label_logIn->setObjectName("label_logIn");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Century")});
        font1.setPointSize(14);
        label_logIn->setFont(font1);

        gridLayout_5->addWidget(label_logIn, 2, 0, 1, 1);

        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setMinimumSize(QSize(0, 40));

        gridLayout_5->addWidget(lineEdit_2, 7, 0, 1, 1);

        enter_nickname = new QLineEdit(centralwidget);
        enter_nickname->setObjectName("enter_nickname");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::MinimumExpanding, QSizePolicy::Policy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(enter_nickname->sizePolicy().hasHeightForWidth());
        enter_nickname->setSizePolicy(sizePolicy1);
        enter_nickname->setMinimumSize(QSize(0, 40));

        gridLayout_5->addWidget(enter_nickname, 4, 0, 1, 1);

        buttonLogIn = new QPushButton(centralwidget);
        buttonLogIn->setObjectName("buttonLogIn");
        QFont font2;
        font2.setBold(true);
        buttonLogIn->setFont(font2);

        gridLayout_5->addWidget(buttonLogIn, 9, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 350, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_5->addItem(verticalSpacer_3, 10, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 200, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_5->addItem(verticalSpacer, 8, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout_5, 5, 1, 1, 3);

        verticalSpacer_5 = new QSpacerItem(20, 200, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_2->addItem(verticalSpacer_5, 1, 1, 1, 1);

        titulo = new QLabel(centralwidget);
        titulo->setObjectName("titulo");
        sizePolicy1.setHeightForWidth(titulo->sizePolicy().hasHeightForWidth());
        titulo->setSizePolicy(sizePolicy1);
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Castellar")});
        font3.setPointSize(36);
        titulo->setFont(font3);
        titulo->setTextFormat(Qt::TextFormat::AutoText);
        titulo->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_2->addWidget(titulo, 3, 1, 1, 3);

        verticalSpacer_8 = new QSpacerItem(20, 700, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_2->addItem(verticalSpacer_8, 2, 1, 1, 1);

        label_registrarse = new QLabel(centralwidget);
        label_registrarse->setObjectName("label_registrarse");

        gridLayout_2->addWidget(label_registrarse, 8, 0, 2, 5);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_4, 6, 4, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 6, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 901, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_password->setText(QCoreApplication::translate("MainWindow", "Password", nullptr));
        label_nickname->setText(QCoreApplication::translate("MainWindow", "Nickname", nullptr));
        label_logIn->setText(QCoreApplication::translate("MainWindow", "Log In", nullptr));
        buttonLogIn->setText(QCoreApplication::translate("MainWindow", "Log In", nullptr));
        titulo->setText(QCoreApplication::translate("MainWindow", "Carta N\303\241utica", nullptr));
        label_registrarse->setText(QCoreApplication::translate("MainWindow", "Don't have an account? Register", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
