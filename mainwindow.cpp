#include "mainwindow.h"
#include "ui_mainwindow.h"

/*
 * Me falta por añadir:
 *  - Que cuando le des al tabulador del registro se use bien la navegacion en los campos
 *  - Poner el logo del ojo al lado de la barra de password para tener la opcion de ver la contraseña (importante) !
 *  - Poner la bbdd para comprobar el usuario
 *
 *  atte: la rakitraki
 */

#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QGraphicsPathItem>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsLineItem>
#include <QPixmap>
#include <QGraphicsColorizeEffect>
#include <QTimer>

#include <QDebug>
#include <QDir>
#include <navigation.h>

#include <QGraphicsSvgItem>
#include <QGraphicsScene>
#include <QGraphicsView>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //cargar problemas
    problemas = nav.problems();

    respbotones.append(ui->radioButton);
    respbotones.append(ui->radioButton_2);
    respbotones.append(ui->radioButton_3);
    respbotones.append(ui->radioButton_4);

    connect(ui->pushButton_3, &QPushButton::clicked, this, &MainWindow::showNextQuestion);

    showNextQuestion(); //para que salga la primera xd

    // Login passwords
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
    ui->enter_password_r1->setEchoMode(QLineEdit::Password);
    ui->enter_password_r2->setEchoMode(QLineEdit::Password);

    // Mostrar login al inicio
    ui->stackedWidget->setCurrentIndex(0);
    ui->toolBar->hide();

    // Conexiones login/register
    connect(ui->buttonLogIn, &QPushButton::clicked, this, &MainWindow::onLogInClicked);
    connect(ui->buttonRegister, &QPushButton::clicked, this, &MainWindow::onRegisterClicked);

    // Links del registro y login
    ui->registrarse->setTextFormat(Qt::RichText);
    ui->registrarse->setTextInteractionFlags(Qt::TextBrowserInteraction);
    ui->registrarse->setOpenExternalLinks(false);
    ui->registrarse->setText("Don't have an account? <a href=\"registrar\">Register</a>");
    connect(ui->registrarse, &QLabel::linkActivated, this, [=](const QString &){ ui->stackedWidget->setCurrentIndex(1);ui->toolBar->hide();});

    ui->iniciar_sesion->setTextFormat(Qt::RichText);
    ui->iniciar_sesion->setTextInteractionFlags(Qt::TextBrowserInteraction);
    ui->iniciar_sesion->setOpenExternalLinks(false);
    ui->iniciar_sesion->setText("Do you already have an account? <a href=\"registrar\"> Log in</a>");
    connect(ui->iniciar_sesion, &QLabel::linkActivated, this, [=](const QString &){ ui->stackedWidget->setCurrentIndex(0);ui->toolBar->hide();});

    // Conexiones botones
    connect(ui->actionPerfil, &QAction::triggered, this, [=](){ ui->stackedWidget->setCurrentIndex(2);ui->toolBar->hide();});
    connect(ui->salirPerfil, &QPushButton::clicked, this, [=](){ ui->stackedWidget->setCurrentIndex(3);ui->toolBar->show();});

    /* Map button
    bool mapaListo = false;
    connect(ui->Map, &QPushButton::clicked, this, [&]() {
        ui->stackedWidget->setCurrentIndex(4);
        if (!mapaListo) {
            setupMap();
            mapaListo = true;
        }
    });
    */

    scene = new QGraphicsScene(this);
    scene->installEventFilter(this);
    ui->graphicsView->setScene(scene);
    QPixmap pm(":/images/carta_nautica.jpg");
    mapItem = scene->addPixmap(pm);
    ui->graphicsView->scale(0.3, 0.3);
    ui->graphicsView->setDragMode(QGraphicsView::ScrollHandDrag);
    scale = 0.2;

    connect(ui->zoomIn, &QToolButton::clicked, this, &MainWindow::zoomInS);
    connect(ui->zoomOut, &QToolButton::clicked, this, &MainWindow::zoomOutS);
    connect(ui->lapiz, &QToolButton::clicked, this, &MainWindow::togglePencil);
    connect(ui->cursor, &QToolButton::clicked, this, &MainWindow::toggleCursor);
    connect(ui->goma, &QToolButton::clicked, this, &MainWindow::toggleRubber);
    connect(ui->nuevaPag, &QToolButton::clicked, this, &MainWindow::clearAllDrawings);
    connect(ui->marca, &QToolButton::clicked, this, &MainWindow::placeMark);
    connect(ui->regla, &QToolButton::clicked, this, &MainWindow::toggleSvgRuler);
    connect(ui->ojo, &QToolButton::clicked, this, &MainWindow::togglePointExtremes);
    connect(ui->texto, &QToolButton::clicked, this, &MainWindow::toggleText);

    sidebarVisible = true;
    ui->sidebarButton->setIcon(QIcon(":/images/flechaIzq.png"));
    ui->sidebarButton_2->setIcon(QIcon(":/images/flechaIzq.png"));
    sidebarAnimation = new QPropertyAnimation(ui->sidebar_2, "maximumWidth", this);
    sidebarAnimation->setDuration(300);

    // 2. CONEXIÓN DEL BOTÓN
    // Asegúrate de que el nombre del objeto sea correcto (el botón dentro del sidebar)
    connect(ui->sidebarButton, &QPushButton::clicked, this, &MainWindow::toggleSidebar);
    connect(ui->sidebarButton_2, &QPushButton::clicked, this, &MainWindow::toggleSidebar);

    //conexion a un problema
    connect(ui->Problema_Random, &QPushButton::clicked, this, [=](){ ui->sidebar_2->setCurrentIndex(1);});
    connect(ui->Problema_1, &QPushButton::clicked, this, [=](){ ui->sidebar_2->setCurrentIndex(1);});

    rulerSvgItem = new RotatableSvgItem(":/images/ruler.svg");
    scene->addItem(rulerSvgItem);
    // Ocultar por defecto, se mostrará al activar el modo
    rulerSvgItem->setVisible(false);

    QTimer *updateTimer = new QTimer(this); //Se usa para actualizar las marcas del 'ojo'
    connect(updateTimer, &QTimer::timeout, this, [=](){
        if (eyeActive) {
            QList<QGraphicsItem*> selected = scene->selectedItems();
            if (!selected.isEmpty()) {
                showPointExtremes(selected.first());
            }
        }
    });
    updateTimer->start(50); // cada 50 ms revisa la posición

}

void MainWindow::setupMap() //funcion para hacer los cambios al mapa
{}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::zoomInS()
{
    applyZoom(1.15);
}

void MainWindow::zoomOutS()
{
    applyZoom(1.0 / 1.15);
}

void MainWindow::applyZoom(double factor)
{
    double newScale = scale * factor;

    const double minScale = 0.01;
    const double maxScale = 1;

    if (newScale < minScale) {
        factor = minScale / scale;
        newScale = minScale;

    } else if (newScale > maxScale) {
        factor = maxScale / scale;
        newScale = maxScale;
    }
    ui->graphicsView->scale(factor, factor);
    scale = newScale;
}

void MainWindow::onLogInClicked()
{
    QString nickname = ui->enter_nickname->text().trimmed();
    QString password = ui->lineEdit_2->text().trimmed();
    User *u = nav.authenticate(nickname, password);

    if (u) {
        ui->stackedWidget->setCurrentIndex(3); // Si lo ha hecho bien, adelante
        ui->toolBar->show();
    } else {
        QMessageBox::warning(this, "Incorrecto", "LOGIN INCORRECTO");
    }

    if (nickname.isEmpty() || password.isEmpty()) {
        ui->stackedWidget->setCurrentIndex(
            0); // Que no pueda pasar al siguiente paso si no se ha logeado bien
        QMessageBox::warning(this,
                             "Advertencia",
                             "Por favor, introduce el nickname y/o contraseña correctos.");
        return;
    }
}

void MainWindow::onRegisterClicked()
{
    QString nameReg = ui->enter_nickname_reg->text().trimmed();
    QString birthDate = ui->enter_birth_date->text().trimmed();
    QString mail = ui->enter_mail->text().trimmed();
    QString password1 = ui->enter_password_r1->text().trimmed();
    QString password2 = ui->enter_password_r2->text().trimmed();

    if (nameReg.isEmpty() || password1.isEmpty() || password2.isEmpty() || password1 != password2) {
        ui->stackedWidget->setCurrentIndex(
            1); // Que no pueda pasar al siguiente paso si no se ha logeado bien
        QMessageBox::warning(this,
                             "Advertencia",
                             "Por favor, introduce el nickname y/o contraseña correctos.");
        return;
    }

    QDate fecha = QDate::fromString(birthDate, "dd/MM/yyyy");
    if (!fecha.isValid()) {
        QMessageBox::warning(this,
                             "Fecha inválida",
                             "Introduce una fecha válida en formato dd/MM/yyyy.");
        return;
    }

    QRegularExpression emailRegex(R"((^[^\s@]+@[^\s@]+\.[^\s@]+$))");
    if (!emailRegex.match(mail).hasMatch()) {
        QMessageBox::warning(this,
                             "Email inválido",
                             "Introduce un email válido (ej: usuario@dominio.com).");
        return;
    }

    //crear el usuario
    QImage avatar(":/images/userIcono.png"); //foto por defecto (esto habrá que arreglarlo xd)

    User u(nameReg, mail, password1, avatar, fecha);

    nav.addUser(u);

    //Ponerlo en el perfil
    ui->nombre->setText("Nickname: " + nameReg);
    ui->nacimiento->setText("Date birth: " + birthDate);
    ui->email->setText("Email: " + mail);
    ui->contrasenya->setText("Password: " + password1);

    ui->stackedWidget->setCurrentIndex(2); // Si lo ha hecho bien, adelante
}

void MainWindow::toggleSidebar()
{
    const int fullWidth = 300;
    const int closedWidth = 100; // O 30, si quieres que el botón quede parcialmente visible

    int startValue;
    int endValue;

    if (sidebarVisible) {
        startValue = fullWidth;
        endValue = closedWidth;
        sidebarVisible = false;
        ui->label->setVisible(false);
        ui->pushButton_2->setVisible(false);
        ui->pushButton_3->setVisible(false);
        for (int i = 0; i < respbotones.size(); ++i) {
            respbotones[i]->setVisible(false);
        }

        ui->sidebarButton->setIcon(QIcon(":/images/flechaDer.png"));
        ui->sidebarButton_2->setIcon(QIcon(":/images/flechaDer.png"));

    } else {
        startValue = closedWidth;
        endValue = fullWidth;
        sidebarVisible = true;
        ui->label->setVisible(true);
        ui->pushButton_2->setVisible(true);
        ui->pushButton_3->setVisible(true);
        for (int i = 0; i < respbotones.size(); ++i) {
            respbotones[i]->setVisible(true);
        }

        ui->sidebarButton->setIcon(QIcon(":/images/flechaIzq.png"));
        ui->sidebarButton_2->setIcon(QIcon(":/images/flechaIzq.png"));
    }

    // Iniciar Animación
    sidebarAnimation->setStartValue(startValue);
    sidebarAnimation->setEndValue(endValue);
    sidebarAnimation->start();
}

void MainWindow::showNextQuestion()
{
    if (preg_actual >= problemas.size())
        preg_actual = 0; // reiniciar si llegamos al final

    const Problem &p = problemas[preg_actual];

    ui->label->setText(p.text());

    // actualizar radiobuttons
    for (int i = 0; i < respbotones.size(); ++i) {
        if (i < p.answers().size()) {
            respbotones[i]->setText(p.answers()[i].text());
            respbotones[i]->setVisible(true);
            respbotones[i]->setChecked(false);
        } else {
            respbotones[i]->setVisible(false);
        }
    }

    preg_actual++;
}

void MainWindow::togglePencil()
{
    drawingMode = true;
    erasingMode = false;
    markingMode = false;
    measuringMode = false;
    textMode = false;

    // Desactivamos el arrastre del mapa para que no se mueva mientras pintamos
    ui->graphicsView->setDragMode(QGraphicsView::NoDrag);

    // Cambiamos el cursor visualmente para que sepa que va a pintar
    ui->graphicsView->setCursor(Qt::CrossCursor);
}

void MainWindow::toggleRubber() // <--- NUEVA IMPLEMENTACIÓN
{
    drawingMode = false;
    erasingMode = true;
    markingMode = false;
    measuringMode = false;
    textMode = false;

    ui->graphicsView->setDragMode(QGraphicsView::NoDrag); // No queremos arrastrar mapa
    ui->graphicsView->setCursor(Qt::ForbiddenCursor); // Icono de "prohibido" o goma
}

void MainWindow::toggleCursor()
{
    drawingMode = false;
    erasingMode = false;
    markingMode = false;
    measuringMode = false;
    textMode = false;

    // Volvemos al modo de arrastrar el mapa
    ui->graphicsView->setDragMode(QGraphicsView::ScrollHandDrag);

    // Restauramos el cursor por defecto
    ui->graphicsView->setCursor(Qt::ArrowCursor);
}

void MainWindow::clearAllDrawings()
{
    for (QGraphicsItem *item : scene->items()) {
        // Si el objeto NO es el mapa, lo borramos
        if (item != mapItem && (item->type() == QGraphicsPathItem::Type ||
                                item->type() == QGraphicsPixmapItem::Type || // Chinchetas
                                item->type() == QGraphicsLineItem::Type ||   // Reglas
                                item->type() == QGraphicsTextItem::Type ||
                                item->type() == QGraphicsItemGroup::Type)) {  // Textos
            scene->removeItem(item);
            delete item;
        }
    }
}

void MainWindow::placeMark()
{
    drawingMode = false;
    erasingMode = false;
    measuringMode = false;
    markingMode = true; // Activamos modo marca
    textMode = false;

    ui->graphicsView->setDragMode(QGraphicsView::NoDrag);
    // Usamos un cursor que parezca que va a señalar algo
    ui->graphicsView->setCursor(Qt::PointingHandCursor);
}

void MainWindow::toggleSvgRuler(){
    // Desactivar todos los demás modos de dibujo
    drawingMode = false;
    erasingMode = false;
    markingMode = false;
    measuringMode = false; // El modo regla lineal (si existe)
    textMode = false;

    svgRulerActive = !svgRulerActive;

    if (rulerSvgItem) {
        rulerSvgItem->setVisible(svgRulerActive);
        rulerSvgItem->setSelected(svgRulerActive); // Para que se resalte y se pueda mover inmediatamente
    }

    if (svgRulerActive) {
        ui->graphicsView->setDragMode(QGraphicsView::NoDrag); // Permitimos la interacción directa con el item SVG
        ui->graphicsView->setCursor(Qt::OpenHandCursor); // Cursor que sugiere arrastrar el objeto
    } else {
        toggleCursor(); // Volver al modo normal de arrastre del mapa
    }
}

void MainWindow::hidePointExtremes()
{
    if (eyeProjectionGroup) {
        scene->removeItem(eyeProjectionGroup);
        delete eyeProjectionGroup;
        eyeProjectionGroup = nullptr;
    }
}

void MainWindow::showPointExtremes(QGraphicsItem *point)
{
    if (!point || !mapItem)
        return;

    // Borrar si existían
    hidePointExtremes();

    eyeProjectionGroup = new QGraphicsItemGroup();

    QPointF p = point->scenePos();

    QRectF mapRect = mapItem->boundingRect();
    QPointF topLeft = mapItem->mapToScene(mapRect.topLeft());
    QPointF bottomRight = mapItem->mapToScene(mapRect.bottomRight());

    QPen pen(Qt::darkGreen, 1, Qt::DashLine); // Se ha puesto asi para que se visualice "destacando" estas marcas
    // De color verde porque de color rojo se podría malinterpretar con que se ha hecho "mal"

    // Proyección vertical
    QGraphicsLineItem *vertical =
        new QGraphicsLineItem(QLineF(p.x(), topLeft.y(), p.x(), bottomRight.y()));
    vertical->setPen(pen);

    // Proyección horizontal
    QGraphicsLineItem *horizontal =
        new QGraphicsLineItem(QLineF(topLeft.x(), p.y(), bottomRight.x(), p.y()));
    horizontal->setPen(pen);

    eyeProjectionGroup->addToGroup(vertical);
    eyeProjectionGroup->addToGroup(horizontal);

    scene->addItem(eyeProjectionGroup);
}

void MainWindow::togglePointExtremes(){
    QList<QGraphicsItem*> selected = scene->selectedItems();

    // Validación básica
    if (selected.isEmpty()) {
        QMessageBox::information(this,
                                 "Marcar extremos",
                                 "Selecciona primero un punto en la carta.");
        return;
    }

    QGraphicsItem *item = selected.first();

    // Si ya está activo → ocultar
    if (eyeActive) {
        hidePointExtremes();
        eyeActive = false;
        return;
    }

    // Si no está activo → mostrar
    showPointExtremes(item);
    eyeActive = true;
}

void MainWindow::toggleText()
{
    drawingMode = false;
    erasingMode = false;
    markingMode = false;
    measuringMode = false;
    textMode = true;

    ui->graphicsView->setDragMode(QGraphicsView::NoDrag);
    ui->graphicsView->setCursor(Qt::IBeamCursor);
}

bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
    if (watched == scene) {
        QGraphicsSceneMouseEvent *mouseEvent = static_cast<QGraphicsSceneMouseEvent*>(event);

        // ---------------------------------------------------------
        // MODO 1: LÁPIZ (Tu código anterior corregido)
        // ---------------------------------------------------------
        if (drawingMode) {
            if (event->type() == QEvent::GraphicsSceneMousePress) {
                currentPath = QPainterPath();
                currentPath.moveTo(mouseEvent->scenePos());
                QPen pen(Qt::red, 3, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
                currentPathItem = scene->addPath(currentPath, pen);
                return true;
            }
            else if (event->type() == QEvent::GraphicsSceneMouseMove && (mouseEvent->buttons() & Qt::LeftButton)) {
                if (currentPathItem) {
                    currentPath.lineTo(mouseEvent->scenePos());
                    currentPathItem->setPath(currentPath);
                }
                return true;
            }
            else if (event->type() == QEvent::GraphicsSceneMouseRelease) {
                currentPathItem = nullptr;
                return true;
            }
        }

        // ---------------------------------------------------------
        // MODO 2: GOMA
        // ---------------------------------------------------------
        else if (erasingMode) {
            if (event->type() == QEvent::GraphicsSceneMousePress ||
                (event->type() == QEvent::GraphicsSceneMouseMove && (mouseEvent->buttons() & Qt::LeftButton))) {

                QGraphicsItem *item = scene->itemAt(mouseEvent->scenePos(), QTransform());
                if (item && item->group()) {
                    item = item->group();
                }
                // AÑADIMOS "item != mapItem" A LA CONDICIÓN
                if (item && item != mapItem && (
                        item->type() == QGraphicsPathItem::Type ||
                        item->type() == QGraphicsPixmapItem::Type ||
                        item->type() == QGraphicsLineItem::Type ||
                        item->type() == QGraphicsTextItem::Type ||
                        item->type() == QGraphicsItemGroup::Type)) {

                    scene->removeItem(item);
                    delete item;
                    return true;
                }
            }
        }

        // ---------------------------------------------------------
        // MODO 3: MARCA (NUEVO)
        // ---------------------------------------------------------
        else if (markingMode) {
            if (event->type() == QEvent::GraphicsSceneMousePress) {
                // 1. Cargamos la imagen (Asegúrate de tener un icono llamado pin.png o similar en tus recursos)
                // Si no tienes imagen, usa ":/images/flechaIzq.png" temporalmente para probar
                QPixmap pixmap(":/images/iconoChincheta.png");

                // Redimensionamos si es muy grande (opcional)
                pixmap = pixmap.scaled(30, 30, Qt::KeepAspectRatio);

                // 2. Añadimos el objeto al mapa
                QGraphicsPixmapItem *marker = scene->addPixmap(pixmap);

                // 3. Centramos la imagen en el clic (si no, el clic queda en la esquina superior izq de la imagen)
                marker->setOffset(-pixmap.width()/2, -pixmap.height()/2);
                marker->setPos(mouseEvent->scenePos());

                // Opcional: Hacer que la marca se pueda mover después
                marker->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
                return true;
            }
            else if (event->type() == QEvent::GraphicsSceneMouseMove && eyeActive) { // actualizar las posiciones de la chincheta
                // Recalcular las líneas de los extremos del item seleccionado
                QList<QGraphicsItem*> selected = scene->selectedItems();
                if (!selected.isEmpty()) {
                    showPointExtremes(selected.first());
                }
                return true;
            }
        }

        // ---------------------------------------------------------
        // MODO 4: REGLA (NUEVO)
        // ---------------------------------------------------------
        else if (measuringMode) {
            if (event->type() == QEvent::GraphicsSceneMousePress) {
                // Guardamos el punto de inicio
                rulerStartPoint = mouseEvent->scenePos();

                // Creamos una línea azul para diferenciar del lápiz
                QPen rulerPen(Qt::blue, 2, Qt::DashLine);
                currentRulerLine = scene->addLine(QLineF(rulerStartPoint, rulerStartPoint), rulerPen);
                return true;
            }
            else if (event->type() == QEvent::GraphicsSceneMouseMove && (mouseEvent->buttons() & Qt::LeftButton)) {
                if (currentRulerLine) {
                    // Actualizamos el final de la línea mientras arrastras
                    QLineF newLine(rulerStartPoint, mouseEvent->scenePos());
                    currentRulerLine->setLine(newLine);
                }
                return true;
            }
            else if (event->type() == QEvent::GraphicsSceneMouseRelease) {
                if (currentRulerLine) {
                    // Calculamos la distancia (en píxeles)
                    QLineF line = currentRulerLine->line();
                    qreal distance = line.length();

                    // Ponemos un texto con la distancia en el punto medio de la línea
                    QGraphicsTextItem *text = scene->addText(QString("%1 px").arg(int(distance)));
                    text->setDefaultTextColor(Qt::blue);
                    text->setPos((line.p1() + line.p2()) / 2); // Punto medio

                    // Ya no editamos más esta línea
                    currentRulerLine = nullptr;
                }
                return true;
            }
        }
        // ---------------------------------------------------------
        // MODO 5: TEXTO (POST-IT)
        // ---------------------------------------------------------
        // Me falta añadir el ajuste del fondo blanco según el tamaño del texto a introducir - raq
        else if (textMode) {
            if (event->type() == QEvent::GraphicsSceneMousePress) {

                QPointF pos = mouseEvent->scenePos();

                // 1. Crear el texto
                QGraphicsTextItem *textItem = new QGraphicsTextItem();
                textItem->setPlainText("");
                textItem->setTextInteractionFlags(Qt::TextEditorInteraction);
                textItem->setDefaultTextColor(Qt::black);
                textItem->setFlag(QGraphicsItem::ItemIsFocusable, true);

                QFont font;
                font.setPointSize(10);
                textItem->setFont(font);

                // 2. Calcular tamaño
                QRectF textRect = textItem->boundingRect();

                // 3. Fondo
                QGraphicsRectItem *background =
                    new QGraphicsRectItem(textRect.adjusted(-5, -5, 5, 5));
                background->setBrush(Qt::white);
                background->setPen(QPen(Qt::black));

                // 4. Grupo
                QGraphicsItemGroup *group = new QGraphicsItemGroup();
                group->addToGroup(background);
                group->addToGroup(textItem);
                group->setHandlesChildEvents(false); // MUY IMPORTANTE

                textItem->setPos(background->rect().topLeft() + QPointF(5, 5));
                group->setPos(pos);

                group->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
                scene->addItem(group);

                // 5. Dar foco al texto para escribir inmediatamente
                scene->setFocusItem(textItem);
                textItem->setFocus();
                return true;
            }
        }

    }
    return QMainWindow::eventFilter(watched, event);
}
