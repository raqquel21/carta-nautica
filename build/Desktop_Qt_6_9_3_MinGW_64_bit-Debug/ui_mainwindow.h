/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *zoomOut;
    QAction *zoomIn;
    QAction *lapiz;
    QAction *goma;
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
    QWidget *Register;
    QWidget *layoutWidget;
    QGridLayout *gridLayout_10;
    QSpacerItem *verticalSpacer_13;
    QSpacerItem *verticalSpacer_15;
    QLabel *label_enter_nickname_2;
    QLineEdit *enter_password_r2;
    QLabel *label_enter_nickname;
    QLineEdit *enter_password_r1;
    QLabel *label_Register;
    QSpacerItem *verticalSpacer_14;
    QSpacerItem *verticalSpacer_16;
    QLabel *label_password_3;
    QLineEdit *enter_birth_date;
    QLabel *label_password_4;
    QPushButton *buttonRegister;
    QLineEdit *enter_mail;
    QLineEdit *enter_nickname_reg;
    QLabel *label_enter_nickname_3;
    QLabel *titulo_2;
    QLabel *iniciar_sesion;
    QWidget *menuPrincipal;
    QGridLayout *gridLayout;
    QGridLayout *gridLayout_7;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *perfil;
    QSpacerItem *verticalSpacer_2;
    QPushButton *pushButtonVolver;
    QPushButton *Map;
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
    QWidget *page;
    QHBoxLayout *horizontalLayout_4;
    QWidget *sidebar_2;
    QGridLayout *sidebar;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *sidebarButton;
    QLabel *label;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *lapiz_2;
    QToolButton *goma_2;
    QToolButton *zoomIn_2;
    QToolButton *zoomOut_2;
    QGraphicsView *graphicsView;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(683, 537);
        zoomOut = new QAction(MainWindow);
        zoomOut->setObjectName("zoomOut");
        zoomOut->setMenuRole(QAction::MenuRole::NoRole);
        zoomIn = new QAction(MainWindow);
        zoomIn->setObjectName("zoomIn");
        zoomIn->setMenuRole(QAction::MenuRole::NoRole);
        lapiz = new QAction(MainWindow);
        lapiz->setObjectName("lapiz");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/lapiz.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        lapiz->setIcon(icon);
        lapiz->setMenuRole(QAction::MenuRole::NoRole);
        goma = new QAction(MainWindow);
        goma->setObjectName("goma");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/goma.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        goma->setIcon(icon1);
        goma->setMenuRole(QAction::MenuRole::NoRole);
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
        Register = new QWidget();
        Register->setObjectName("Register");
        layoutWidget = new QWidget(Register);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(60, 110, 581, 474));
        gridLayout_10 = new QGridLayout(layoutWidget);
        gridLayout_10->setObjectName("gridLayout_10");
        gridLayout_10->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_13 = new QSpacerItem(20, 200, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_10->addItem(verticalSpacer_13, 13, 1, 1, 1);

        verticalSpacer_15 = new QSpacerItem(20, 350, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_10->addItem(verticalSpacer_15, 17, 1, 1, 1);

        label_enter_nickname_2 = new QLabel(layoutWidget);
        label_enter_nickname_2->setObjectName("label_enter_nickname_2");
        sizePolicy.setHeightForWidth(label_enter_nickname_2->sizePolicy().hasHeightForWidth());
        label_enter_nickname_2->setSizePolicy(sizePolicy);
        label_enter_nickname_2->setFont(font);

        gridLayout_10->addWidget(label_enter_nickname_2, 5, 1, 1, 1);

        enter_password_r2 = new QLineEdit(layoutWidget);
        enter_password_r2->setObjectName("enter_password_r2");
        enter_password_r2->setMinimumSize(QSize(0, 40));

        gridLayout_10->addWidget(enter_password_r2, 15, 1, 1, 1);

        label_enter_nickname = new QLabel(layoutWidget);
        label_enter_nickname->setObjectName("label_enter_nickname");
        sizePolicy.setHeightForWidth(label_enter_nickname->sizePolicy().hasHeightForWidth());
        label_enter_nickname->setSizePolicy(sizePolicy);
        label_enter_nickname->setFont(font);

        gridLayout_10->addWidget(label_enter_nickname, 3, 1, 1, 1);

        enter_password_r1 = new QLineEdit(layoutWidget);
        enter_password_r1->setObjectName("enter_password_r1");
        enter_password_r1->setMinimumSize(QSize(0, 40));

        gridLayout_10->addWidget(enter_password_r1, 12, 1, 1, 1);

        label_Register = new QLabel(layoutWidget);
        label_Register->setObjectName("label_Register");
        label_Register->setFont(font1);

        gridLayout_10->addWidget(label_Register, 2, 1, 1, 1);

        verticalSpacer_14 = new QSpacerItem(20, 100, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_10->addItem(verticalSpacer_14, 10, 1, 1, 1);

        verticalSpacer_16 = new QSpacerItem(20, 250, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_10->addItem(verticalSpacer_16, 1, 1, 1, 1);

        label_password_3 = new QLabel(layoutWidget);
        label_password_3->setObjectName("label_password_3");
        label_password_3->setFont(font);

        gridLayout_10->addWidget(label_password_3, 11, 1, 1, 1);

        enter_birth_date = new QLineEdit(layoutWidget);
        enter_birth_date->setObjectName("enter_birth_date");
        sizePolicy1.setHeightForWidth(enter_birth_date->sizePolicy().hasHeightForWidth());
        enter_birth_date->setSizePolicy(sizePolicy1);
        enter_birth_date->setMinimumSize(QSize(0, 40));

        gridLayout_10->addWidget(enter_birth_date, 6, 1, 1, 1);

        label_password_4 = new QLabel(layoutWidget);
        label_password_4->setObjectName("label_password_4");
        label_password_4->setFont(font);

        gridLayout_10->addWidget(label_password_4, 14, 1, 1, 1);

        buttonRegister = new QPushButton(layoutWidget);
        buttonRegister->setObjectName("buttonRegister");
        buttonRegister->setFont(font2);

        gridLayout_10->addWidget(buttonRegister, 16, 1, 1, 1);

        enter_mail = new QLineEdit(layoutWidget);
        enter_mail->setObjectName("enter_mail");
        sizePolicy1.setHeightForWidth(enter_mail->sizePolicy().hasHeightForWidth());
        enter_mail->setSizePolicy(sizePolicy1);
        enter_mail->setMinimumSize(QSize(0, 40));

        gridLayout_10->addWidget(enter_mail, 9, 1, 1, 1);

        enter_nickname_reg = new QLineEdit(layoutWidget);
        enter_nickname_reg->setObjectName("enter_nickname_reg");
        sizePolicy1.setHeightForWidth(enter_nickname_reg->sizePolicy().hasHeightForWidth());
        enter_nickname_reg->setSizePolicy(sizePolicy1);
        enter_nickname_reg->setMinimumSize(QSize(0, 40));

        gridLayout_10->addWidget(enter_nickname_reg, 4, 1, 1, 1);

        label_enter_nickname_3 = new QLabel(layoutWidget);
        label_enter_nickname_3->setObjectName("label_enter_nickname_3");
        sizePolicy.setHeightForWidth(label_enter_nickname_3->sizePolicy().hasHeightForWidth());
        label_enter_nickname_3->setSizePolicy(sizePolicy);
        label_enter_nickname_3->setFont(font);

        gridLayout_10->addWidget(label_enter_nickname_3, 8, 1, 1, 1);

        titulo_2 = new QLabel(Register);
        titulo_2->setObjectName("titulo_2");
        titulo_2->setGeometry(QRect(60, 10, 547, 73));
        sizePolicy1.setHeightForWidth(titulo_2->sizePolicy().hasHeightForWidth());
        titulo_2->setSizePolicy(sizePolicy1);
        titulo_2->setFont(font3);
        iniciar_sesion = new QLabel(Register);
        iniciar_sesion->setObjectName("iniciar_sesion");
        iniciar_sesion->setGeometry(QRect(10, 620, 551, 20));
        stackedWidget->addWidget(Register);
        menuPrincipal = new QWidget();
        menuPrincipal->setObjectName("menuPrincipal");
        gridLayout = new QGridLayout(menuPrincipal);
        gridLayout->setObjectName("gridLayout");
        gridLayout_7 = new QGridLayout();
        gridLayout_7->setObjectName("gridLayout_7");
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_7->addItem(horizontalSpacer_3, 0, 2, 1, 1);

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

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_7->addItem(verticalSpacer_2, 2, 4, 1, 1);

        pushButtonVolver = new QPushButton(menuPrincipal);
        pushButtonVolver->setObjectName("pushButtonVolver");

        gridLayout_7->addWidget(pushButtonVolver, 2, 2, 1, 1);

        Map = new QPushButton(menuPrincipal);
        Map->setObjectName("Map");

        gridLayout_7->addWidget(Map, 1, 2, 1, 1);


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
        page = new QWidget();
        page->setObjectName("page");
        horizontalLayout_4 = new QHBoxLayout(page);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        sidebar_2 = new QWidget(page);
        sidebar_2->setObjectName("sidebar_2");
        sidebar_2->setMaximumSize(QSize(200, 16777215));
        sidebar = new QGridLayout(sidebar_2);
        sidebar->setObjectName("sidebar");
        sidebar->setSizeConstraint(QLayout::SizeConstraint::SetDefaultConstraint);
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        sidebar->addItem(horizontalSpacer_5, 0, 0, 1, 1);

        sidebarButton = new QPushButton(sidebar_2);
        sidebarButton->setObjectName("sidebarButton");
        sidebarButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"	background-repeat: no-repeat;\n"
"    background-position: center;\n"
"\n"
"    min-width: 48px;\n"
"    min-height: 48px;\n"
"}\n"
"\n"
""));

        sidebar->addWidget(sidebarButton, 0, 1, 1, 1);

        label = new QLabel(sidebar_2);
        label->setObjectName("label");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy3);

        sidebar->addWidget(label, 2, 0, 1, 1);


        horizontalLayout_4->addWidget(sidebar_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        lapiz_2 = new QToolButton(page);
        lapiz_2->setObjectName("lapiz_2");
        lapiz_2->setStyleSheet(QString::fromUtf8("QToolButton {\n"
"    border: none;\n"
"	background-repeat: no-repeat;\n"
"    background-position: center;\n"
"    background-image: url(:/images/lapiz.png);\n"
"\n"
"    min-width: 48px;\n"
"    min-height: 48px;\n"
"}"));
        lapiz_2->setIconSize(QSize(48, 48));

        horizontalLayout_2->addWidget(lapiz_2);

        goma_2 = new QToolButton(page);
        goma_2->setObjectName("goma_2");
        goma_2->setStyleSheet(QString::fromUtf8("QToolButton {\n"
"    border: none;\n"
"	background-repeat: no-repeat;\n"
"    background-position: center;\n"
"    background-image: url(:/images/goma.jpg);\n"
"\n"
"    min-width: 48px;\n"
"    min-height: 48px;\n"
"}"));

        horizontalLayout_2->addWidget(goma_2);

        zoomIn_2 = new QToolButton(page);
        zoomIn_2->setObjectName("zoomIn_2");
        zoomIn_2->setStyleSheet(QString::fromUtf8("QToolButton {\n"
"    border: none;\n"
"	background-repeat: no-repeat;\n"
"    background-position: center;\n"
"    background-image: url(:/images/zoomIn.png);\n"
"\n"
"    min-width: 48px;\n"
"    min-height: 48px;\n"
"}"));

        horizontalLayout_2->addWidget(zoomIn_2);

        zoomOut_2 = new QToolButton(page);
        zoomOut_2->setObjectName("zoomOut_2");
        zoomOut_2->setStyleSheet(QString::fromUtf8("QToolButton {\n"
"    border: none;\n"
"	background-repeat: no-repeat;\n"
"    background-position: center;\n"
"    background-image: url(:/images/zoomOut.png);\n"
"\n"
"    min-width: 48px;\n"
"    min-height: 48px;\n"
"}"));

        horizontalLayout_2->addWidget(zoomOut_2);


        verticalLayout_3->addLayout(horizontalLayout_2);

        graphicsView = new QGraphicsView(page);
        graphicsView->setObjectName("graphicsView");

        verticalLayout_3->addWidget(graphicsView);


        horizontalLayout_4->addLayout(verticalLayout_3);

        stackedWidget->addWidget(page);

        gridLayout_3->addWidget(stackedWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        zoomOut->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        zoomIn->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        lapiz->setText(QCoreApplication::translate("MainWindow", "lapiz", nullptr));
        goma->setText(QCoreApplication::translate("MainWindow", "goma", nullptr));
        label_nickname->setText(QCoreApplication::translate("MainWindow", "Nickname", nullptr));
        label_logIn->setText(QCoreApplication::translate("MainWindow", "Log In", nullptr));
        label_password->setText(QCoreApplication::translate("MainWindow", "Password", nullptr));
        buttonLogIn->setText(QCoreApplication::translate("MainWindow", "Log In", nullptr));
        registrarse->setText(QCoreApplication::translate("MainWindow", "Don't have an account? Register", nullptr));
        titulo->setText(QCoreApplication::translate("MainWindow", "Carta n\303\241utica", nullptr));
        label_enter_nickname_2->setText(QCoreApplication::translate("MainWindow", "Enter your birth date (dd/mm/yyyy)", nullptr));
        label_enter_nickname->setText(QCoreApplication::translate("MainWindow", "Enter your nickname", nullptr));
        label_Register->setText(QCoreApplication::translate("MainWindow", "Register", nullptr));
        label_password_3->setText(QCoreApplication::translate("MainWindow", "Enter the password", nullptr));
        label_password_4->setText(QCoreApplication::translate("MainWindow", "Repeat the password", nullptr));
        buttonRegister->setText(QCoreApplication::translate("MainWindow", "Register", nullptr));
        label_enter_nickname_3->setText(QCoreApplication::translate("MainWindow", "Enter your mail", nullptr));
        titulo_2->setText(QCoreApplication::translate("MainWindow", "Carta n\303\241utica", nullptr));
        iniciar_sesion->setText(QCoreApplication::translate("MainWindow", "Do you already have an account? Log in", nullptr));
        perfil->setText(QString());
        pushButtonVolver->setText(QCoreApplication::translate("MainWindow", "Volver", nullptr));
        Map->setText(QCoreApplication::translate("MainWindow", "Mapa (Provisional)", nullptr));
        salirPerfil->setText(QString());
        contrasenya->setText(QCoreApplication::translate("MainWindow", "Contrase\303\261a:", nullptr));
        nacimiento->setText(QCoreApplication::translate("MainWindow", "Fecha de Nacimiento:", nullptr));
        email->setText(QCoreApplication::translate("MainWindow", "Email:", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        nombre->setText(QCoreApplication::translate("MainWindow", "Nombre:", nullptr));
        cerrarSesion->setText(QCoreApplication::translate("MainWindow", "Cerrar Sesi\303\263n", nullptr));
        sidebarButton->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        lapiz_2->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        goma_2->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        zoomIn_2->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        zoomOut_2->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
