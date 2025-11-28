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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_3;
    QStackedWidget *stackedWidget;
    QWidget *login;
    QGridLayout *gridLayout_6;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QGridLayout *gridLayout_5;
    QLabel *label_nickname;
    QLabel *label_logIn;
    QSpacerItem *verticalSpacer;
    QLineEdit *lineEdit_2;
    QSpacerItem *verticalSpacer_6;
    QLabel *label_password;
    QPushButton *buttonLogIn;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *verticalSpacer_4;
    QLineEdit *enter_nickname;
    QLabel *registrarse;
    QLabel *titulo;
    QWidget *menuPrincipal;
    QGridLayout *gridLayout;
    QGridLayout *gridLayout_7;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer_2;
    QPushButton *pushButtonVolver;
    QPushButton *perfil;
    QWidget *perfil_menu;
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout_2;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *salirPerfil;
    QSpacerItem *verticalSpacer_5;
    QGridLayout *gridLayout_8;
    QLabel *contrasenya;
    QSpacerItem *verticalSpacer_7;
    QSpacerItem *verticalSpacer_8;
    QLabel *nacimiento;
    QLabel *email;
    QPushButton *pushButton;
    QLabel *nombre;
    QPushButton *cerrarSesion;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(683, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout_3 = new QGridLayout(centralwidget);
        gridLayout_3->setObjectName("gridLayout_3");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setMinimumSize(QSize(661, 0));
        login = new QWidget();
        login->setObjectName("login");
        login->setMinimumSize(QSize(661, 0));
        gridLayout_6 = new QGridLayout(login);
        gridLayout_6->setObjectName("gridLayout_6");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::MinimumExpanding, QSizePolicy::Policy::Minimum);

        gridLayout_6->addItem(horizontalSpacer, 1, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::MinimumExpanding, QSizePolicy::Policy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_2, 1, 0, 1, 1);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName("gridLayout_5");
        label_nickname = new QLabel(login);
        label_nickname->setObjectName("label_nickname");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_nickname->sizePolicy().hasHeightForWidth());
        label_nickname->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        label_nickname->setFont(font);

        gridLayout_5->addWidget(label_nickname, 3, 1, 1, 1);

        label_logIn = new QLabel(login);
        label_logIn->setObjectName("label_logIn");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Century")});
        font1.setPointSize(14);
        label_logIn->setFont(font1);

        gridLayout_5->addWidget(label_logIn, 2, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 200, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_5->addItem(verticalSpacer, 8, 1, 1, 1);

        lineEdit_2 = new QLineEdit(login);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setMinimumSize(QSize(0, 40));

        gridLayout_5->addWidget(lineEdit_2, 7, 1, 1, 1);

        verticalSpacer_6 = new QSpacerItem(20, 100, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_5->addItem(verticalSpacer_6, 5, 1, 1, 1);

        label_password = new QLabel(login);
        label_password->setObjectName("label_password");
        label_password->setFont(font);

        gridLayout_5->addWidget(label_password, 6, 1, 1, 1);

        buttonLogIn = new QPushButton(login);
        buttonLogIn->setObjectName("buttonLogIn");
        QFont font2;
        font2.setBold(true);
        buttonLogIn->setFont(font2);

        gridLayout_5->addWidget(buttonLogIn, 9, 1, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 350, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_5->addItem(verticalSpacer_3, 10, 1, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 250, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_5->addItem(verticalSpacer_4, 1, 1, 1, 1);

        enter_nickname = new QLineEdit(login);
        enter_nickname->setObjectName("enter_nickname");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::MinimumExpanding, QSizePolicy::Policy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(enter_nickname->sizePolicy().hasHeightForWidth());
        enter_nickname->setSizePolicy(sizePolicy1);
        enter_nickname->setMinimumSize(QSize(0, 40));

        gridLayout_5->addWidget(enter_nickname, 4, 1, 1, 1);


        gridLayout_6->addLayout(gridLayout_5, 1, 1, 1, 1);

        registrarse = new QLabel(login);
        registrarse->setObjectName("registrarse");

        gridLayout_6->addWidget(registrarse, 2, 1, 1, 1);

        titulo = new QLabel(login);
        titulo->setObjectName("titulo");
        sizePolicy1.setHeightForWidth(titulo->sizePolicy().hasHeightForWidth());
        titulo->setSizePolicy(sizePolicy1);
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Castellar")});
        font3.setPointSize(36);
        titulo->setFont(font3);

        gridLayout_6->addWidget(titulo, 0, 1, 1, 1);

        stackedWidget->addWidget(login);
        menuPrincipal = new QWidget();
        menuPrincipal->setObjectName("menuPrincipal");
        gridLayout = new QGridLayout(menuPrincipal);
        gridLayout->setObjectName("gridLayout");
        gridLayout_7 = new QGridLayout();
        gridLayout_7->setObjectName("gridLayout_7");
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_7->addItem(horizontalSpacer_3, 0, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_7->addItem(verticalSpacer_2, 1, 4, 1, 1);

        pushButtonVolver = new QPushButton(menuPrincipal);
        pushButtonVolver->setObjectName("pushButtonVolver");

        gridLayout_7->addWidget(pushButtonVolver, 1, 2, 1, 1);

        perfil = new QPushButton(menuPrincipal);
        perfil->setObjectName("perfil");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(perfil->sizePolicy().hasHeightForWidth());
        perfil->setSizePolicy(sizePolicy2);
        perfil->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        perfil->setAutoFillBackground(false);
        perfil->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"	background-repeat: no-repeat;\n"
"    background-position: center;\n"
"    background-image: url(:/images/userIcono.png);\n"
"\n"
"    min-width: 48px;\n"
"    min-height: 48px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-image: url(:/images/userIconoIllum.png);\n"
"	background-repeat: no-repeat;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-image: url(:/images/userIconoIllum.png);\n"
"	background-repeat: no-repeat;\n"
"}\n"
""));
        perfil->setIconSize(QSize(48, 48));
        perfil->setFlat(true);

        gridLayout_7->addWidget(perfil, 0, 4, 1, 1);


        gridLayout->addLayout(gridLayout_7, 0, 0, 1, 1);

        stackedWidget->addWidget(menuPrincipal);
        perfil_menu = new QWidget();
        perfil_menu->setObjectName("perfil_menu");
        gridLayout_4 = new QGridLayout(perfil_menu);
        gridLayout_4->setObjectName("gridLayout_4");
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_4, 0, 0, 1, 1);

        salirPerfil = new QPushButton(perfil_menu);
        salirPerfil->setObjectName("salirPerfil");
        sizePolicy2.setHeightForWidth(salirPerfil->sizePolicy().hasHeightForWidth());
        salirPerfil->setSizePolicy(sizePolicy2);
        salirPerfil->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"	background-repeat: no-repeat;\n"
"    background-position: center;\n"
"    background-image: url(:/images/x.png);\n"
"\n"
"    min-width: 48px;\n"
"    min-height: 48px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-image: url(:/images/ixIlumin.png);\n"
"	background-repeat: no-repeat;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-image: url(:/images/ixIlumin.png);\n"
"	background-repeat: no-repeat;\n"
"}\n"
""));
        salirPerfil->setIconSize(QSize(48, 48));

        gridLayout_2->addWidget(salirPerfil, 0, 1, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_2->addItem(verticalSpacer_5, 1, 1, 1, 1);

        gridLayout_8 = new QGridLayout();
        gridLayout_8->setObjectName("gridLayout_8");
        contrasenya = new QLabel(perfil_menu);
        contrasenya->setObjectName("contrasenya");

        gridLayout_8->addWidget(contrasenya, 4, 0, 1, 1);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_8->addItem(verticalSpacer_7, 6, 0, 1, 1);

        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_8->addItem(verticalSpacer_8, 1, 0, 1, 1);

        nacimiento = new QLabel(perfil_menu);
        nacimiento->setObjectName("nacimiento");

        gridLayout_8->addWidget(nacimiento, 5, 0, 1, 1);

        email = new QLabel(perfil_menu);
        email->setObjectName("email");

        gridLayout_8->addWidget(email, 3, 0, 1, 1);

        pushButton = new QPushButton(perfil_menu);
        pushButton->setObjectName("pushButton");

        gridLayout_8->addWidget(pushButton, 0, 0, 1, 1);

        nombre = new QLabel(perfil_menu);
        nombre->setObjectName("nombre");

        gridLayout_8->addWidget(nombre, 2, 0, 1, 1);

        cerrarSesion = new QPushButton(perfil_menu);
        cerrarSesion->setObjectName("cerrarSesion");
        QFont font4;
        font4.setBold(true);
        font4.setItalic(false);
        font4.setUnderline(true);
        cerrarSesion->setFont(font4);
        cerrarSesion->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: black;\n"
"    color: white;\n"
"}"));

        gridLayout_8->addWidget(cerrarSesion, 7, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout_8, 1, 0, 1, 1);


        gridLayout_4->addLayout(gridLayout_2, 0, 1, 1, 1);

        stackedWidget->addWidget(perfil_menu);

        gridLayout_3->addWidget(stackedWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_nickname->setText(QCoreApplication::translate("MainWindow", "Nickname", nullptr));
        label_logIn->setText(QCoreApplication::translate("MainWindow", "Log In", nullptr));
        label_password->setText(QCoreApplication::translate("MainWindow", "Password", nullptr));
        buttonLogIn->setText(QCoreApplication::translate("MainWindow", "Log In", nullptr));
        registrarse->setText(QCoreApplication::translate("MainWindow", "Don't have an account? Register", nullptr));
        titulo->setText(QCoreApplication::translate("MainWindow", "Carta n\303\241utica", nullptr));
        pushButtonVolver->setText(QCoreApplication::translate("MainWindow", "Volver", nullptr));
        perfil->setText(QString());
        salirPerfil->setText(QString());
        contrasenya->setText(QCoreApplication::translate("MainWindow", "Contrase\303\261a:", nullptr));
        nacimiento->setText(QCoreApplication::translate("MainWindow", "Fecha de Nacimiento:", nullptr));
        email->setText(QCoreApplication::translate("MainWindow", "Email:", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        nombre->setText(QCoreApplication::translate("MainWindow", "Nombre:", nullptr));
        cerrarSesion->setText(QCoreApplication::translate("MainWindow", "Cerrar Sesi\303\263n", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
