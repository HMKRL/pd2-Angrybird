#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#define x_0 144
#define y_0 490
#define meter_x0 7.15f
#define meter_y0 15.5f
#define PI 3.1415926

#include "movepoint.h"
#include "gameitem.h"
#include "bird.h"
#include "planet.h"
#include "land.h"
#include "contectlistener.h"
#include "block.h"
#include "enemy.h"
#include "yellowbird.h"
#include "blackbird.h"
#include "flappybird.h"
#include "resultdialog.h"
#include "tnt.h"

#include <QMainWindow>
#include <QDebug>
#include <Box2D/Box2D.h>
#include <QEvent>
#include <QGraphicsScene>
#include <QMouseEvent>
#include <QTimer>
#include <QList>
#include <QEvent>
#include <QVector>
#include <QQueue>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void closeEvent(QCloseEvent*);
    void mousePressEvent(QMouseEvent *event);
    bool eventFilter(QObject *,QEvent *event);
    QVector<GameItem*> ITEM;
    QQueue<Bird*> BIRD;

public slots:
    void getScore(int score);
    void enemyKilled();

signals:
    void quitGame();

private slots:
    void tick();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    b2World *world;
    QTimer timer;
    QSizeF world_meter;
    QSizeF world_pixel;
    QPointF dragstart;
    QPointF dragstop;
    bool pressed;
    QGraphicsPixmapItem *arrow;
    void addItems();
    void addBird();
    ContectListener *arcane_ear;
    void deleteItem();
    int Score;
    bool gameStarted;
    int enemyCount;
    int birdCount;
    bool ready;
};

#endif // MAINWINDOW_H
