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
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionPerfil;
    QWidget *centralwidget;
    QGridLayout *gridLayout_3;
    QStackedWidget *stackedWidget;
    QWidget *login;
    QGridLayout *gridLayout_6;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QGridLayout *gridLayout_5;
    QLabel *label_logIn;
    QLabel *label_password;
    QLabel *label_nickname;
    QSpacerItem *verticalSpacer_3;
    QLineEdit *lineEdit_2;
    QPushButton *buttonLogIn;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_4;
    QLineEdit *enter_nickname;
    QSpacerItem *verticalSpacer_6;
    QSpacerItem *verticalSpacer_12;
    QLabel *registrarse;
    QLabel *titulo;
    QWidget *Register;
    QGridLayout *gridLayout_9;
    QLabel *titulo_2;
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
    QLabel *iniciar_sesion;
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
    QStackedWidget *sidebar_2;
    QWidget *Elegir_problema;
    QGridLayout *gridLayout_13;
    QPushButton *sidebarButton_2;
    QPushButton *Problema_Random;
    QSpacerItem *verticalSpacer_18;
    QLabel *Problemas;
    QWidget *Resolver_Problema;
    QGridLayout *sidebar;
    QSpacerItem *verticalSpacer_10;
    QPushButton *verificarButton;
    QSpacerItem *verticalSpacer_9;
    QRadioButton *radioButton_4;
    QSpacerItem *horizontalSpacer_5;
    QLabel *enunciadoLabel;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QSpacerItem *verticalSpacer_11;
    QRadioButton *radioButton;
    QPushButton *sigButton;
    QPushButton *sidebarButton;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *nuevaPag;
    QToolButton *cursor;
    QToolButton *lapiz;
    QVBoxLayout *verticalLayout;
    QSlider *grosorSlider;
    QPushButton *colorButton;
    QToolButton *goma;
    QToolButton *texto;
    QToolButton *marca;
    QToolButton *ojo;
    QToolButton *regla;
    QToolButton *transportador;
    QToolButton *compas;
    QToolButton *zoomIn;
    QSlider *zoomSlider;
    QToolButton *zoomOut;
    QGraphicsView *graphicsView;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(823, 670);
        actionPerfil = new QAction(MainWindow);
        actionPerfil->setObjectName("actionPerfil");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/userIcono.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionPerfil->setIcon(icon);
        actionPerfil->setMenuRole(QAction::MenuRole::NoRole);
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
        label_logIn = new QLabel(login);
        label_logIn->setObjectName("label_logIn");
        QFont font;
        font.setFamilies({QString::fromUtf8("Century")});
        font.setPointSize(14);
        label_logIn->setFont(font);

        gridLayout_5->addWidget(label_logIn, 2, 1, 1, 1);

        label_password = new QLabel(login);
        label_password->setObjectName("label_password");
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        label_password->setFont(font1);

        gridLayout_5->addWidget(label_password, 7, 1, 1, 1);

        label_nickname = new QLabel(login);
        label_nickname->setObjectName("label_nickname");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_nickname->sizePolicy().hasHeightForWidth());
        label_nickname->setSizePolicy(sizePolicy);
        label_nickname->setFont(font1);

        gridLayout_5->addWidget(label_nickname, 3, 1, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 350, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_5->addItem(verticalSpacer_3, 11, 1, 1, 1);

        lineEdit_2 = new QLineEdit(login);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setMinimumSize(QSize(0, 40));

        gridLayout_5->addWidget(lineEdit_2, 8, 1, 1, 1);

        buttonLogIn = new QPushButton(login);
        buttonLogIn->setObjectName("buttonLogIn");
        QFont font2;
        font2.setBold(true);
        buttonLogIn->setFont(font2);

        gridLayout_5->addWidget(buttonLogIn, 10, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 200, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_5->addItem(verticalSpacer, 9, 1, 1, 1);

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

        verticalSpacer_6 = new QSpacerItem(20, 100, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_5->addItem(verticalSpacer_6, 5, 1, 1, 1);

        verticalSpacer_12 = new QSpacerItem(20, 100, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_5->addItem(verticalSpacer_12, 6, 1, 1, 1);


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
        gridLayout_9 = new QGridLayout(Register);
        gridLayout_9->setObjectName("gridLayout_9");
        titulo_2 = new QLabel(Register);
        titulo_2->setObjectName("titulo_2");
        sizePolicy1.setHeightForWidth(titulo_2->sizePolicy().hasHeightForWidth());
        titulo_2->setSizePolicy(sizePolicy1);
        titulo_2->setFont(font3);

        gridLayout_9->addWidget(titulo_2, 0, 0, 1, 1);

        gridLayout_10 = new QGridLayout();
        gridLayout_10->setObjectName("gridLayout_10");
        verticalSpacer_13 = new QSpacerItem(20, 200, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_10->addItem(verticalSpacer_13, 13, 1, 1, 1);

        verticalSpacer_15 = new QSpacerItem(20, 350, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_10->addItem(verticalSpacer_15, 17, 1, 1, 1);

        label_enter_nickname_2 = new QLabel(Register);
        label_enter_nickname_2->setObjectName("label_enter_nickname_2");
        sizePolicy.setHeightForWidth(label_enter_nickname_2->sizePolicy().hasHeightForWidth());
        label_enter_nickname_2->setSizePolicy(sizePolicy);
        label_enter_nickname_2->setFont(font1);

        gridLayout_10->addWidget(label_enter_nickname_2, 5, 1, 1, 1);

        enter_password_r2 = new QLineEdit(Register);
        enter_password_r2->setObjectName("enter_password_r2");
        enter_password_r2->setMinimumSize(QSize(0, 40));

        gridLayout_10->addWidget(enter_password_r2, 15, 1, 1, 1);

        label_enter_nickname = new QLabel(Register);
        label_enter_nickname->setObjectName("label_enter_nickname");
        sizePolicy.setHeightForWidth(label_enter_nickname->sizePolicy().hasHeightForWidth());
        label_enter_nickname->setSizePolicy(sizePolicy);
        label_enter_nickname->setFont(font1);

        gridLayout_10->addWidget(label_enter_nickname, 3, 1, 1, 1);

        enter_password_r1 = new QLineEdit(Register);
        enter_password_r1->setObjectName("enter_password_r1");
        enter_password_r1->setMinimumSize(QSize(0, 40));

        gridLayout_10->addWidget(enter_password_r1, 12, 1, 1, 1);

        label_Register = new QLabel(Register);
        label_Register->setObjectName("label_Register");
        label_Register->setFont(font);

        gridLayout_10->addWidget(label_Register, 2, 1, 1, 1);

        verticalSpacer_14 = new QSpacerItem(20, 100, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_10->addItem(verticalSpacer_14, 10, 1, 1, 1);

        verticalSpacer_16 = new QSpacerItem(20, 250, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_10->addItem(verticalSpacer_16, 1, 1, 1, 1);

        label_password_3 = new QLabel(Register);
        label_password_3->setObjectName("label_password_3");
        label_password_3->setFont(font1);

        gridLayout_10->addWidget(label_password_3, 11, 1, 1, 1);

        enter_birth_date = new QLineEdit(Register);
        enter_birth_date->setObjectName("enter_birth_date");
        sizePolicy1.setHeightForWidth(enter_birth_date->sizePolicy().hasHeightForWidth());
        enter_birth_date->setSizePolicy(sizePolicy1);
        enter_birth_date->setMinimumSize(QSize(0, 40));

        gridLayout_10->addWidget(enter_birth_date, 6, 1, 1, 1);

        label_password_4 = new QLabel(Register);
        label_password_4->setObjectName("label_password_4");
        label_password_4->setFont(font1);

        gridLayout_10->addWidget(label_password_4, 14, 1, 1, 1);

        buttonRegister = new QPushButton(Register);
        buttonRegister->setObjectName("buttonRegister");
        buttonRegister->setFont(font2);

        gridLayout_10->addWidget(buttonRegister, 16, 1, 1, 1);

        enter_mail = new QLineEdit(Register);
        enter_mail->setObjectName("enter_mail");
        sizePolicy1.setHeightForWidth(enter_mail->sizePolicy().hasHeightForWidth());
        enter_mail->setSizePolicy(sizePolicy1);
        enter_mail->setMinimumSize(QSize(0, 40));

        gridLayout_10->addWidget(enter_mail, 9, 1, 1, 1);

        enter_nickname_reg = new QLineEdit(Register);
        enter_nickname_reg->setObjectName("enter_nickname_reg");
        sizePolicy1.setHeightForWidth(enter_nickname_reg->sizePolicy().hasHeightForWidth());
        enter_nickname_reg->setSizePolicy(sizePolicy1);
        enter_nickname_reg->setMinimumSize(QSize(0, 40));

        gridLayout_10->addWidget(enter_nickname_reg, 4, 1, 1, 1);

        label_enter_nickname_3 = new QLabel(Register);
        label_enter_nickname_3->setObjectName("label_enter_nickname_3");
        sizePolicy.setHeightForWidth(label_enter_nickname_3->sizePolicy().hasHeightForWidth());
        label_enter_nickname_3->setSizePolicy(sizePolicy);
        label_enter_nickname_3->setFont(font1);

        gridLayout_10->addWidget(label_enter_nickname_3, 8, 1, 1, 1);


        gridLayout_9->addLayout(gridLayout_10, 1, 0, 1, 1);

        iniciar_sesion = new QLabel(Register);
        iniciar_sesion->setObjectName("iniciar_sesion");

        gridLayout_9->addWidget(iniciar_sesion, 2, 0, 1, 1);

        stackedWidget->addWidget(Register);
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
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
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
        sidebar_2 = new QStackedWidget(page);
        sidebar_2->setObjectName("sidebar_2");
        sidebar_2->setMaximumSize(QSize(200, 16777215));
        Elegir_problema = new QWidget();
        Elegir_problema->setObjectName("Elegir_problema");
        gridLayout_13 = new QGridLayout(Elegir_problema);
        gridLayout_13->setObjectName("gridLayout_13");
        sidebarButton_2 = new QPushButton(Elegir_problema);
        sidebarButton_2->setObjectName("sidebarButton_2");
        sidebarButton_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"	background-repeat: no-repeat;\n"
"    background-position: center;\n"
"\n"
"    min-width: 48px;\n"
"    min-height: 48px;\n"
"}\n"
""));

        gridLayout_13->addWidget(sidebarButton_2, 0, 1, 1, 1);

        Problema_Random = new QPushButton(Elegir_problema);
        Problema_Random->setObjectName("Problema_Random");

        gridLayout_13->addWidget(Problema_Random, 4, 0, 1, 1);

        verticalSpacer_18 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_13->addItem(verticalSpacer_18, 3, 0, 1, 1);

        Problemas = new QLabel(Elegir_problema);
        Problemas->setObjectName("Problemas");

        gridLayout_13->addWidget(Problemas, 0, 0, 1, 1);

        sidebar_2->addWidget(Elegir_problema);
        Resolver_Problema = new QWidget();
        Resolver_Problema->setObjectName("Resolver_Problema");
        sidebar = new QGridLayout(Resolver_Problema);
        sidebar->setObjectName("sidebar");
        sidebar->setSizeConstraint(QLayout::SizeConstraint::SetDefaultConstraint);
        verticalSpacer_10 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        sidebar->addItem(verticalSpacer_10, 3, 0, 1, 1);

        verificarButton = new QPushButton(Resolver_Problema);
        verificarButton->setObjectName("verificarButton");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::MinimumExpanding, QSizePolicy::Policy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(verificarButton->sizePolicy().hasHeightForWidth());
        verificarButton->setSizePolicy(sizePolicy3);

        sidebar->addWidget(verificarButton, 9, 0, 1, 1);

        verticalSpacer_9 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        sidebar->addItem(verticalSpacer_9, 8, 0, 1, 1);

        radioButton_4 = new QRadioButton(Resolver_Problema);
        radioButton_4->setObjectName("radioButton_4");
        QSizePolicy sizePolicy4(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(radioButton_4->sizePolicy().hasHeightForWidth());
        radioButton_4->setSizePolicy(sizePolicy4);

        sidebar->addWidget(radioButton_4, 7, 0, 1, 2);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        sidebar->addItem(horizontalSpacer_5, 0, 0, 1, 1);

        enunciadoLabel = new QLabel(Resolver_Problema);
        enunciadoLabel->setObjectName("enunciadoLabel");
        QSizePolicy sizePolicy5(QSizePolicy::Policy::MinimumExpanding, QSizePolicy::Policy::Preferred);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(enunciadoLabel->sizePolicy().hasHeightForWidth());
        enunciadoLabel->setSizePolicy(sizePolicy5);
        enunciadoLabel->setWordWrap(true);

        sidebar->addWidget(enunciadoLabel, 2, 0, 1, 2);

        radioButton_2 = new QRadioButton(Resolver_Problema);
        radioButton_2->setObjectName("radioButton_2");
        sizePolicy4.setHeightForWidth(radioButton_2->sizePolicy().hasHeightForWidth());
        radioButton_2->setSizePolicy(sizePolicy4);

        sidebar->addWidget(radioButton_2, 5, 0, 1, 2);

        radioButton_3 = new QRadioButton(Resolver_Problema);
        radioButton_3->setObjectName("radioButton_3");
        sizePolicy4.setHeightForWidth(radioButton_3->sizePolicy().hasHeightForWidth());
        radioButton_3->setSizePolicy(sizePolicy4);

        sidebar->addWidget(radioButton_3, 6, 0, 1, 2);

        verticalSpacer_11 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        sidebar->addItem(verticalSpacer_11, 1, 0, 1, 1);

        radioButton = new QRadioButton(Resolver_Problema);
        radioButton->setObjectName("radioButton");
        QSizePolicy sizePolicy6(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Maximum);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(radioButton->sizePolicy().hasHeightForWidth());
        radioButton->setSizePolicy(sizePolicy6);

        sidebar->addWidget(radioButton, 4, 0, 1, 2);

        sigButton = new QPushButton(Resolver_Problema);
        sigButton->setObjectName("sigButton");
        sizePolicy4.setHeightForWidth(sigButton->sizePolicy().hasHeightForWidth());
        sigButton->setSizePolicy(sizePolicy4);

        sidebar->addWidget(sigButton, 9, 1, 1, 1);

        sidebarButton = new QPushButton(Resolver_Problema);
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

        sidebar_2->addWidget(Resolver_Problema);

        horizontalLayout_4->addWidget(sidebar_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        nuevaPag = new QToolButton(page);
        nuevaPag->setObjectName("nuevaPag");
        nuevaPag->setStyleSheet(QString::fromUtf8("QToolButton {\n"
"    border: none;\n"
"	background-repeat: no-repeat;\n"
"    background-position: center;\n"
"    background-image: url(:/images/newpag.png);\n"
"\n"
"    min-width: 48px;\n"
"    min-height: 48px;\n"
"}\n"
"\n"
"QToolButton:hover {\n"
"    background-image: url(:/images/newpagIlum.png);\n"
"	background-repeat: no-repeat;\n"
"}\n"
"\n"
"QToolButton:pressed {\n"
"	background-image: url(:/images/newpagIlum.png);\n"
"	background-repeat: no-repeat;\n"
"}\n"
"QToolButton:checked {\n"
"\n"
"    border: 2px solid #FF8C00; \n"
"    border-radius: 4px;\n"
"    \n"
" \n"
"    background-image: url(:/images/newpagIlum.png); \n"
"    background-repeat: no-repeat;\n"
"}\n"
"QToolButton:checked {\n"
"\n"
"    border: 2px solid #CCCCCC; \n"
"    border-radius: 4px;\n"
"    \n"
" \n"
"    background-image: url(:/images/newpagIlum.png); \n"
"    background-repeat: no-repeat;\n"
"}"));
        nuevaPag->setCheckable(false);

        horizontalLayout_2->addWidget(nuevaPag);

        cursor = new QToolButton(page);
        cursor->setObjectName("cursor");
        cursor->setStyleSheet(QString::fromUtf8("QToolButton {\n"
"    border: none;\n"
"	background-repeat: no-repeat;\n"
"    background-position: center;\n"
"    background-image: url(:/images/cursor.png);\n"
"\n"
"    min-width: 48px;\n"
"    min-height: 48px;\n"
"}\n"
"\n"
"QToolButton:hover {\n"
"    background-image: url(:/images/cursorIlum.png);\n"
"	background-repeat: no-repeat;\n"
"}\n"
"\n"
"QToolButton:pressed {\n"
"	background-image: url(:/images/cursorIlum.png);\n"
"	background-repeat: no-repeat;\n"
"}\n"
"QToolButton:checked {\n"
"\n"
"    border: 2px solid #CCCCCC; \n"
"    border-radius: 4px;\n"
"    \n"
" \n"
"    background-image: url(:/images/cursorIlum.png); \n"
"    background-repeat: no-repeat;\n"
"}\n"
""));
        cursor->setCheckable(true);

        horizontalLayout_2->addWidget(cursor);

        lapiz = new QToolButton(page);
        lapiz->setObjectName("lapiz");
        lapiz->setStyleSheet(QString::fromUtf8("QToolButton {\n"
"    border: none;\n"
"	background-repeat: no-repeat;\n"
"    background-position: center;\n"
"    background-image: url(:/images/lapiz.png);\n"
"\n"
"    min-width: 48px;\n"
"    min-height: 48px;\n"
"}\n"
"\n"
"QToolButton:hover {\n"
"    background-image: url(:/images/lapizIlum.png);\n"
"	background-repeat: no-repeat;\n"
"}\n"
"\n"
"QToolButton:pressed {\n"
"	background-image: url(:/images/lapizIlum.png);\n"
"	background-repeat: no-repeat;\n"
"}\n"
"QToolButton:checked {\n"
"\n"
"    border: 2px solid #CCCCCC; \n"
"    border-radius: 4px;\n"
"    \n"
" \n"
"    background-image: url(:/images/lapizIlum.png); \n"
"    background-repeat: no-repeat;\n"
"}\n"
"\n"
""));
        lapiz->setIconSize(QSize(48, 48));
        lapiz->setCheckable(true);
        lapiz->setChecked(false);

        horizontalLayout_2->addWidget(lapiz);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        grosorSlider = new QSlider(page);
        grosorSlider->setObjectName("grosorSlider");
        grosorSlider->setMinimumSize(QSize(0, 30));
        grosorSlider->setMaximumSize(QSize(75, 16777215));
        grosorSlider->setOrientation(Qt::Orientation::Horizontal);

        verticalLayout->addWidget(grosorSlider);

        colorButton = new QPushButton(page);
        colorButton->setObjectName("colorButton");
        colorButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #FF0000; \n"
"  \n"
"}"));

        verticalLayout->addWidget(colorButton);


        horizontalLayout_2->addLayout(verticalLayout);

        goma = new QToolButton(page);
        goma->setObjectName("goma");
        goma->setStyleSheet(QString::fromUtf8("QToolButton {\n"
"    border: none;\n"
"	background-repeat: no-repeat;\n"
"    background-position: center;\n"
"    background-image: url(:/images/goma.png);\n"
"\n"
"    min-width: 48px;\n"
"    min-height: 48px;\n"
"}\n"
"\n"
"QToolButton:hover {\n"
"    background-image: url(:/images/gomaIlum.png);\n"
"	background-repeat: no-repeat;\n"
"}\n"
"\n"
"QToolButton:pressed {\n"
"	background-image: url(:/images/gomaIlum.png);\n"
"	background-repeat: no-repeat;\n"
"}\n"
"QToolButton:checked {\n"
"\n"
"    border: 2px solid #CCCCCC; \n"
"    border-radius: 4px;\n"
"    \n"
" \n"
"    background-image: url(:/images/gomaIlum.png); \n"
"    background-repeat: no-repeat;\n"
"}"));
        goma->setCheckable(true);

        horizontalLayout_2->addWidget(goma);

        texto = new QToolButton(page);
        texto->setObjectName("texto");
        texto->setStyleSheet(QString::fromUtf8("QToolButton {\n"
"    border: none;\n"
"	background-repeat: no-repeat;\n"
"    background-position: center;\n"
"    background-image: url(:/images/texto.png);\n"
"\n"
"    min-width: 48px;\n"
"    min-height: 48px;\n"
"}\n"
"\n"
"QToolButton:hover {\n"
"    background-image: url(:/images/textoIlum.png);\n"
"	background-repeat: no-repeat;\n"
"}\n"
"\n"
"QToolButton:pressed {\n"
"	background-image: url(:/images/textoIlum.png);\n"
"	background-repeat: no-repeat;\n"
"}\n"
"QToolButton:checked {\n"
"\n"
"    border: 2px solid #CCCCCC; \n"
"    border-radius: 4px;\n"
"    \n"
" \n"
"    background-image: url(:/images/textoIlum.png); \n"
"    background-repeat: no-repeat;\n"
"}"));
        texto->setCheckable(true);

        horizontalLayout_2->addWidget(texto);

        marca = new QToolButton(page);
        marca->setObjectName("marca");
        marca->setStyleSheet(QString::fromUtf8("QToolButton {\n"
"    border: none;\n"
"	background-repeat: no-repeat;\n"
"    background-position: center;\n"
"    background-image: url(:/images/marca.png);\n"
"\n"
"    min-width: 48px;\n"
"    min-height: 48px;\n"
"}\n"
"\n"
"QToolButton:hover {\n"
"    background-image: url(:/images/marcaIlum.png);\n"
"	background-repeat: no-repeat;\n"
"}\n"
"\n"
"QToolButton:pressed {\n"
"	background-image: url(:/images/marcaIlum.png);\n"
"	background-repeat: no-repeat;\n"
"}\n"
"QToolButton:checked {\n"
"\n"
"    border: 2px solid #CCCCCC; \n"
"    border-radius: 4px;\n"
"    \n"
" \n"
"    background-image: url(:/images/marcaIlum.png); \n"
"    background-repeat: no-repeat;\n"
"}"));
        marca->setCheckable(true);

        horizontalLayout_2->addWidget(marca);

        ojo = new QToolButton(page);
        ojo->setObjectName("ojo");
        ojo->setStyleSheet(QString::fromUtf8("QToolButton {\n"
"    border: none;\n"
"	background-repeat: no-repeat;\n"
"    background-position: center;\n"
"    background-image: url(:/images/ojo.png);\n"
"\n"
"    min-width: 48px;\n"
"    min-height: 48px;\n"
"}\n"
"\n"
"QToolButton:hover {\n"
"    background-image: url(:/images/ojoIlum.png);\n"
"	background-repeat: no-repeat;\n"
"}\n"
"\n"
"QToolButton:pressed {\n"
"	background-image: url(:/images/ojoIlum.png);\n"
"	background-repeat: no-repeat;\n"
"}\n"
"QToolButton:checked {\n"
"\n"
"    border: 2px solid #CCCCCC; \n"
"    border-radius: 4px;\n"
"    \n"
" \n"
"    background-image: url(:/images/ojoIlum.png); \n"
"    background-repeat: no-repeat;\n"
"}"));
        ojo->setCheckable(true);

        horizontalLayout_2->addWidget(ojo);

        regla = new QToolButton(page);
        regla->setObjectName("regla");
        regla->setStyleSheet(QString::fromUtf8("QToolButton {\n"
"    border: none;\n"
"	background-repeat: no-repeat;\n"
"    background-position: center;\n"
"    background-image: url(:/images/rule.png);\n"
"\n"
"    min-width: 48px;\n"
"    min-height: 48px;\n"
"}\n"
"\n"
"QToolButton:hover {\n"
"    background-image: url(:/images/ruleIlum.png);\n"
"	background-repeat: no-repeat;\n"
"}\n"
"\n"
"QToolButton:pressed {\n"
"	background-image: url(:/images/ruleIlum.png);\n"
"	background-repeat: no-repeat;\n"
"}\n"
"QToolButton:checked {\n"
"\n"
"    border: 2px solid #CCCCCC; \n"
"    border-radius: 4px;\n"
"    \n"
" \n"
"    background-image: url(:/images/ruleIlum.png); \n"
"    background-repeat: no-repeat;\n"
"}"));
        regla->setCheckable(true);

        horizontalLayout_2->addWidget(regla);

        transportador = new QToolButton(page);
        transportador->setObjectName("transportador");
        transportador->setStyleSheet(QString::fromUtf8("QToolButton {\n"
"    border: none;\n"
"	background-repeat: no-repeat;\n"
"    background-position: center;\n"
"    background-image: url(:/images/transportador.png);\n"
"\n"
"    min-width: 48px;\n"
"    min-height: 48px;\n"
"}\n"
"\n"
"QToolButton:hover {\n"
"    background-image: url(:/images/transportadorIlum.png);\n"
"	background-repeat: no-repeat;\n"
"}\n"
"\n"
"QToolButton:pressed {\n"
"	background-image: url(:/images/transportadorIlum.png);\n"
"	background-repeat: no-repeat;\n"
"}\n"
"QToolButton:checked {\n"
"\n"
"    border: 2px solid #CCCCCC; \n"
"    border-radius: 4px;\n"
"    \n"
" \n"
"    background-image: url(:/images/transportadorIlum.png); \n"
"    background-repeat: no-repeat;\n"
"}"));
        transportador->setCheckable(true);

        horizontalLayout_2->addWidget(transportador);

        compas = new QToolButton(page);
        compas->setObjectName("compas");
        compas->setStyleSheet(QString::fromUtf8("QToolButton {\n"
"    border: none;\n"
"	background-repeat: no-repeat;\n"
"    background-position: center;\n"
"    background-image: url(:/images/compas.png);\n"
"\n"
"    min-width: 48px;\n"
"    min-height: 48px;\n"
"}\n"
"\n"
"QToolButton:hover {\n"
"    background-image: url(:/images/compasIlum.png);\n"
"	background-repeat: no-repeat;\n"
"}\n"
"\n"
"QToolButton:pressed {\n"
"	background-image: url(:/images/compasIlum.png);\n"
"	background-repeat: no-repeat;\n"
"}\n"
""));
        compas->setCheckable(true);

        horizontalLayout_2->addWidget(compas);

        zoomIn = new QToolButton(page);
        zoomIn->setObjectName("zoomIn");
        zoomIn->setStyleSheet(QString::fromUtf8("QToolButton {\n"
"    border: none;\n"
"	background-repeat: no-repeat;\n"
"    background-position: center;\n"
"    background-image: url(:/images/zoomIn.png);\n"
"\n"
"    min-width: 48px;\n"
"    min-height: 48px;\n"
"}\n"
"QToolButton:hover {\n"
"    background-image: url(:/images/zoomInIlum.png);\n"
"	background-repeat: no-repeat;\n"
"}\n"
"\n"
"QToolButton:pressed {\n"
"	background-image: url(:/images/zoomInIlum.png);\n"
"	background-repeat: no-repeat;\n"
"}\n"
""));
        zoomIn->setCheckable(true);

        horizontalLayout_2->addWidget(zoomIn);

        zoomSlider = new QSlider(page);
        zoomSlider->setObjectName("zoomSlider");
        zoomSlider->setMinimumSize(QSize(50, 48));
        zoomSlider->setMaximumSize(QSize(200, 48));
        zoomSlider->setOrientation(Qt::Orientation::Horizontal);

        horizontalLayout_2->addWidget(zoomSlider);

        zoomOut = new QToolButton(page);
        zoomOut->setObjectName("zoomOut");
        zoomOut->setStyleSheet(QString::fromUtf8("QToolButton {\n"
"    border: none;\n"
"	background-repeat: no-repeat;\n"
"    background-position: center;\n"
"    background-image: url(:/images/zoomOut.png);\n"
"\n"
"    min-width: 48px;\n"
"    min-height: 48px;\n"
"}\n"
"QToolButton:hover {\n"
"    background-image: url(:/images/zoomOutIlum.png);\n"
"	background-repeat: no-repeat;\n"
"}\n"
"\n"
"QToolButton:pressed {\n"
"	background-image: url(:/images/zoomOutIlum.png);\n"
"	background-repeat: no-repeat;\n"
"}"));
        zoomOut->setCheckable(true);

        horizontalLayout_2->addWidget(zoomOut);


        verticalLayout_3->addLayout(horizontalLayout_2);

        graphicsView = new QGraphicsView(page);
        graphicsView->setObjectName("graphicsView");

        verticalLayout_3->addWidget(graphicsView);


        horizontalLayout_4->addLayout(verticalLayout_3);

        stackedWidget->addWidget(page);

        gridLayout_3->addWidget(stackedWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName("toolBar");
        QFont font5;
        font5.setHintingPreference(QFont::PreferDefaultHinting);
        toolBar->setFont(font5);
        toolBar->setLayoutDirection(Qt::LayoutDirection::RightToLeft);
        toolBar->setMovable(false);
        toolBar->setIconSize(QSize(45, 45));
        MainWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, toolBar);

        toolBar->addAction(actionPerfil);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(3);
        sidebar_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionPerfil->setText(QCoreApplication::translate("MainWindow", "Perfil", nullptr));
        label_logIn->setText(QCoreApplication::translate("MainWindow", "Log In", nullptr));
        label_password->setText(QCoreApplication::translate("MainWindow", "Password", nullptr));
        label_nickname->setText(QCoreApplication::translate("MainWindow", "Nickname", nullptr));
        lineEdit_2->setText(QCoreApplication::translate("MainWindow", "User123!", nullptr));
        buttonLogIn->setText(QCoreApplication::translate("MainWindow", "Log In", nullptr));
        enter_nickname->setText(QCoreApplication::translate("MainWindow", "user1", nullptr));
        registrarse->setText(QCoreApplication::translate("MainWindow", "Don't have an account? Register", nullptr));
        titulo->setText(QCoreApplication::translate("MainWindow", "Carta n\303\241utica", nullptr));
        titulo_2->setText(QCoreApplication::translate("MainWindow", "Carta n\303\241utica", nullptr));
        label_enter_nickname_2->setText(QCoreApplication::translate("MainWindow", "Enter your birth date (dd/mm/yyyy)", nullptr));
        label_enter_nickname->setText(QCoreApplication::translate("MainWindow", "Enter your nickname", nullptr));
        label_Register->setText(QCoreApplication::translate("MainWindow", "Register", nullptr));
        label_password_3->setText(QCoreApplication::translate("MainWindow", "Enter the password", nullptr));
        label_password_4->setText(QCoreApplication::translate("MainWindow", "Repeat the password", nullptr));
        buttonRegister->setText(QCoreApplication::translate("MainWindow", "Register", nullptr));
        label_enter_nickname_3->setText(QCoreApplication::translate("MainWindow", "Enter your mail", nullptr));
        iniciar_sesion->setText(QCoreApplication::translate("MainWindow", "Do you already have an account? Log in", nullptr));
        salirPerfil->setText(QString());
        contrasenya->setText(QCoreApplication::translate("MainWindow", "Contrase\303\261a:", nullptr));
        nacimiento->setText(QCoreApplication::translate("MainWindow", "Fecha de Nacimiento:", nullptr));
        email->setText(QCoreApplication::translate("MainWindow", "Email:", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        nombre->setText(QCoreApplication::translate("MainWindow", "Nombre:", nullptr));
        cerrarSesion->setText(QCoreApplication::translate("MainWindow", "Cerrar Sesi\303\263n", nullptr));
        sidebarButton_2->setText(QString());
        Problema_Random->setText(QCoreApplication::translate("MainWindow", "Problema Random", nullptr));
        Problemas->setText(QCoreApplication::translate("MainWindow", "Problemas", nullptr));
        verificarButton->setText(QCoreApplication::translate("MainWindow", "Verificar", nullptr));
        radioButton_4->setText(QCoreApplication::translate("MainWindow", "RadioButton", nullptr));
        enunciadoLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        radioButton_2->setText(QCoreApplication::translate("MainWindow", "RadioButton", nullptr));
        radioButton_3->setText(QCoreApplication::translate("MainWindow", "RadioButton", nullptr));
        radioButton->setText(QCoreApplication::translate("MainWindow", "RadioButton", nullptr));
        sigButton->setText(QCoreApplication::translate("MainWindow", "Siguiente Pregunta", nullptr));
        sidebarButton->setText(QString());
        nuevaPag->setText(QString());
        cursor->setText(QString());
        lapiz->setText(QString());
        colorButton->setText(QString());
        goma->setText(QString());
        texto->setText(QString());
        marca->setText(QString());
        ojo->setText(QString());
        regla->setText(QString());
        transportador->setText(QString());
        compas->setText(QString());
        zoomIn->setText(QString());
        zoomOut->setText(QString());
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
