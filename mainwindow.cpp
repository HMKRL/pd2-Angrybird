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
    addItems();
    addBird();

    //bird shoot arrow
    arrow = new QGraphicsPixmapItem;
    arrow->setPixmap(QPixmap(":/image/res/arrow.png").scaled(200, 18, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    arrow->setTransformOriginPoint(arrow->pixmap().width()/2, arrow->pixmap().height()/2);
    arrow->setTransformationMode(Qt::SmoothTransformation);
    arrow->setVisible(false);
    scene->addItem(arrow);

    Score = 0;
    enemyCount = 1;
    birdCount = 4;
    gameStarted = false;
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
    QPointF Pos = MovePoint::pixel2meter(event->pos());
    //ITEM.push_back(new Block(Pos.x(), Pos.y(), 4.0f, 0.4f, -44.14f, Block::Wood, world, scene, &timer, this));
    Bird *b;
    if(!BIRD.empty()) {
        b = BIRD.front();
        if(!b->launched) {
            dragstart = event->pos();
            pressed = true;
        }
        else {
            b->active();
        }
    }
}

bool MainWindow::eventFilter(QObject*, QEvent *event)
{
    if(event->type() == QEvent::MouseButtonRelease) {
        arrow->setVisible(false);
        pressed = false;
        dragstop = static_cast<QMouseEvent*>(event)->pos();
        if(!BIRD.empty() && !BIRD.front()->launched) {
            BIRD.front()->setLinearVelocity(b2Vec2((dragstart.x()-dragstop.x())/40,-(dragstart.y()-dragstop.y())/40));
            BIRD.front()->launched = true;
            gameStarted = true;
            ready = false;
        }
    }
    else if(pressed && event->type() == QEvent::MouseMove) {
        if(!BIRD.empty() && !BIRD.front()->launched) {
            QPointF temp = static_cast<QMouseEvent*>(event)->pos();
            arrow->resetTransform();
            arrow->setPos(QPointF(x_0, y_0) - QPointF(100, 9));
            arrow->setRotation(qAtan2(temp.y()-dragstart.y(), temp.x()-dragstart.x())*180/PI);
            arrow->setScale(qSqrt(qPow(temp.y()-dragstart.y(), 2) + qPow(temp.x()-dragstart.x(), 2))/250 + 0.75);
            arrow->setVisible(true);
        }
    }
    return false;
}

void MainWindow::getScore(int score)
{
    if(gameStarted) {
        Score += score;
        ui->lcdNumber->display(Score);
    }
}

void MainWindow::enemyKilled()
{
    --enemyCount;
}

void MainWindow::tick()
{
    deleteItem();
    world->Step(1.0/60.0, 6, 2);
    scene->update();
    /*if((birdCount == 0 || enemyCount == 0) && ready) {
        resultDialog *res = new resultDialog(Score, enemyCount, birdCount);
        res->show();
        if(res->exec()) {
            for(auto it = ITEM.begin();it != ITEM.end();++it) {
                delete *it;
            }
            ITEM.clear();
            while(!BIRD.empty()) {
                delete BIRD.front();
                BIRD.pop_front();
            }
            addItems();
            addBird();
            birdCount = 4;
            enemyCount = 1;
            Score = 0;
        }
        else this->close();
    }*/
}

void MainWindow::addItems()
{
    //chunk 1
    ITEM.push_back(new Block(39.0f, 26.9f, 1.5f, 1.5f, 0.0f, Block::Wood, world, scene, &timer, this));
    ITEM.push_back(new Block(40.5f, 26.9f, 1.5f, 1.5f, 0.0f, Block::Wood, world, scene, &timer, this));
    ITEM.push_back(new Block(39.75f, 28.4f, 1.5f, 1.5f, 0.0f, Block::Glass, world, scene, &timer, this));
    ITEM.push_back(new Block(39.75f, 29.9f, 1.5f, 1.5f, 0.0f, Block::Stone, world, scene, &timer, this));
    //chunk 2
        //layer 1
    ITEM.push_back(new Block(43.44f, 25.35f, 1.5f, 1.5f, -44.14f, Block::Wood, world, scene, &timer, this));
    ITEM.push_back(new Block(46.69f, 22.19f, 1.5f, 1.5f, -44.14f, Block::Wood, world, scene, &timer, this));
        //layer 2
    ITEM.push_back(new Block(44.49f, 26.42f, 1.5f, 1.5f, -44.14f, Block::Wood, world, scene, &timer, this));
    ITEM.push_back(new Block(47.73f, 23.29f, 1.5f, 1.5f, -44.14f, Block::Wood, world, scene, &timer, this));
        //rod
    ITEM.push_back(new Block(46.76f, 25.56f, 4.0f, 0.4f, -44.14f, Block::Wood, world, scene, &timer, this));

    ITEM.push_back(new Enemy(39.75f, 31.5f, 0.8f, &timer, world, scene, this));
    ITEM.push_back(new Planet(7.2f, 6.75f, 4.375f, world, this));
    ITEM.push_back(new Planet(39.75f, 18.7f, 6.3f, world, this));
    ITEM.push_back(new Land(40.15f, 25.4f, 2.1f, 0.02f, 0.0f, world, this));
    ITEM.push_back(new Land(44.82f, 22.9f, 3.52f, 0.02f, -44.0f, world, this));
    ITEM.push_back(new Land(45.95f, 16.63f, 3.62f, 0.02f, 70.5f, world, this));
    ITEM.push_back(new Land(43.9f, 13.03f, 0.6f, 0.02f, -30.0f, world, this));
    ITEM.push_back(new Land(37.8f, 25.15f, 0.3f, 0.02f, 45.0f, world, this));
}

void MainWindow::addBird()
{
    BIRD.push_back(new Bird(meter_x0, meter_y0, 0.8f, &timer, world, scene, this));
    BIRD.push_back(new yellowBird(meter_x0, meter_y0, 0.8f, &timer, world, scene, this));
    BIRD.push_back(new blackBird(meter_x0, meter_y0, 0.8f, &timer, world, scene, this));
    BIRD.push_back(new flappyBird(meter_x0, meter_y0, 0.8f, &timer, world, scene, this));

    BIRD.front()->setVisible(true);
    ready = true;
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
    if(!BIRD.empty() && BIRD.front()->toDelete) {
        delete BIRD.front();
        --birdCount;
        BIRD.pop_front();
        if(!BIRD.empty()) BIRD.front()->setVisible(true);
        ready = true;
    }
}
