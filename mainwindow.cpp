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
    arcane_ear = new ContectListener;
    world->SetContactListener(arcane_ear);
    world_meter = QSizeF(64, 40);
    world_pixel = ui->graphicsView->size();
    GameItem::setGlobalSize(world_meter, world_pixel);
    MovePoint::setGlobalSize(world_meter, world_pixel);
    addStaticItems();
    b1 = new Bird(meter_x0, meter_y0, 1.0f, &timer, world, scene, QPixmap(":/image/res/Normal_Bird.png"));

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
    //qDebug() << MovePoint::pixel2meter(event->pos());
    pressed = true;
}

bool MainWindow::eventFilter(QObject*, QEvent *event)
{
    if(event->type() == QEvent::MouseButtonRelease) {
        arrow->setVisible(false);
        pressed = false;
        dragstop = static_cast<QMouseEvent*>(event)->pos();
        b1->setLinearVelocity(b2Vec2((dragstart.x()-dragstop.x())/40,-(dragstart.y()-dragstop.y())/40));
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
    deleteItem();
    world->Step(1.0/60.0, 6, 2);
    scene->update();
}

void MainWindow::addStaticItems()
{
    Planet *p1 = new Planet(7.2f, 6.75f, 4.375f, world);
    Planet *p2 = new Planet(39.75f, 18.7f, 6.3f, world);
    Land *l1 = new Land(40.15f, 25.4f, 2.1f, 0.01f, 0.0f, world);
    Land *l2 = new Land(44.82f, 22.9f, 3.52f, 0.01f, -44.0f, world);
    Land *l3 = new Land(45.95f, 16.63f, 3.62f, 0.02f, 70.5f, world);
    Land *l4 = new Land(43.9f, 13.03f, 0.6f, 0.02f, -30.0f, world);
    Land *l5 = new Land(37.8f, 25.15f, 0.3f, 0.02f, 45.0f, world);
    Block *B = new Block(40.0f, 26.41f, 2.0f, 2.0f, 0.0f, Block::Stone, world, scene, &timer);
    Block *B2 = new Block(46.5f, 23.7f, 2.0f, 2.0f, -44.0f, Block::Stone, world, scene, &timer);
    Block *B3 = new Block(40.0f, 28.41f, 2.0f, 2.0f, 0.0f, Block::Glass, world, scene, &timer);
    Block *B4 = new Block(40.0f, 30.41f, 2.0f, 2.0f, 0.0f, Block::Wood, world, scene, &timer);
    ITEM.push_back(B);
    ITEM.push_back(B2);
    ITEM.push_back(B3);
    ITEM.push_back(B4);
    ITEM.push_back(p1);
    ITEM.push_back(p2);
}

void MainWindow::deleteItem()
{
    QVector<GameItem*>::Iterator it;
    for(it = ITEM.begin();it != ITEM.end();++it) {
        if((*it)->toDelete) {
            delete (*it);
            ITEM.erase(it);
        }
    }
}
