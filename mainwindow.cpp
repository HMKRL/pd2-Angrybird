#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qApp->installEventFilter(this);
    pressed = false;
    scene = new QGraphicsScene(0,0,ui->graphicsView->width(),ui->graphicsView->height());
    ui->graphicsView->setScene(scene);

    //create a world without gravity, gravity will provide by planets.
    world = new b2World(b2Vec2(0.0f, 0.0f));
    world_meter = QSizeF(64, 40);
    world_pixel = ui->graphicsView->size();
    GameItem::setGlobalSize(world_meter, world_pixel);
    MovePoint::setGlobalSize(world_meter, world_pixel);
    Planet *p1 = new Planet(7.2f, 6.75f, 4.375f, world);
    Planet *p2 = new Planet(39.75f, 18.7f, 6.3f, world);
    b1 = new Bird(7.15f, 15.5f, 1.0f, &timer, world, scene, QPixmap(":/image/res/Normal_Bird.png"));

    //bird shoot arrow
    arrow = new QGraphicsPixmapItem;
    arrow->setPixmap(QPixmap(":/image/res/arrow.png").scaled(200, 18, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    arrow->setTransformOriginPoint(arrow->pixmap().width()/2, arrow->pixmap().height()/2);
    arrow->setTransformationMode(Qt::SmoothTransformation);
    arrow->setVisible(false);
    scene->addItem(arrow);

    connect(&timer,SIGNAL(timeout()),this,SLOT(tick()));
    timer.start(60/1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent*)
{
    qDebug() << "signal emitted.";
    emit quitGame();
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    dragstart = event->pos();
    qDebug() << MovePoint::pixel2meter(event->pos());
    pressed = true;
}

bool MainWindow::eventFilter(QObject*, QEvent *event)
{
    if(event->type() == QEvent::MouseButtonRelease) {
        arrow->setVisible(false);
        pressed = false;
        dragstop = static_cast<QMouseEvent*>(event)->pos();
        b1->setLinearVelocity(b2Vec2((dragstart.x()-dragstop.x())/30,-(dragstart.y()-dragstop.y())/30));
    }
    else if(pressed && event->type() == QEvent::MouseMove) {
        QPointF temp = static_cast<QMouseEvent*>(event)->pos();
        arrow->resetTransform();
        arrow->setPos(QPointF(x_0, y_0) - QPointF(100, 9));
        arrow->setRotation(qAtan2(temp.y()-dragstart.y(), temp.x()-dragstart.x())*180/PI);
        arrow->setScale(qSqrt(qPow(temp.y()-dragstart.y(), 2) + qPow(temp.x()-dragstart.x(), 2))/250 + 0.75);
        arrow->setVisible(true);
    }
    return false;
}

void MainWindow::tick()
{
    world->Step(1.0/60.0, 6, 2);
    scene->update();
}
