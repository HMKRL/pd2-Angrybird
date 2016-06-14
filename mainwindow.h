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

#include <QMainWindow>
#include <QDebug>
#include <Box2D/Box2D.h>
#include <QEvent>
#include <QGraphicsScene>
#include <QMouseEvent>
#include <QTimer>
#include <QList>
#include <QEvent>

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

signals:
    void quitGame();

private slots:
    void tick();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    b2World *world;
    QList<GameItem *> itemList;
    QTimer timer;
    QSizeF world_meter;
    QSizeF world_pixel;
    QPointF dragstart;
    QPointF dragstop;
    Bird *b1;
    bool pressed;
    QGraphicsPixmapItem *arrow;
    void addStaticItems();
    ContectListener *arcane_ear;
};

#endif // MAINWINDOW_H
