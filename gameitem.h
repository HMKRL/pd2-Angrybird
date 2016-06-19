#ifndef GAMEITEM_H
#define GAMEITEM_H

#include <Box2D/Box2D.h>
#include <QGraphicsPixmapItem>
#include <QSizeF>
#include <QPainter>
#include <QThread>
#include <QTransform>
#include <QtMath>
#include <QObject>
#include <QTimer>
#include <QGraphicsScene>
#include <QString>
#include <QSound>
#include <QDebug>
#include <QMainWindow>

#define PI 3.1415926

class GameItem : public QObject
{
    Q_OBJECT
public:
    GameItem(b2World *world, QMainWindow *p);
    virtual ~GameItem();
    static void setGlobalSize(QSizeF Meter, QSizeF Pixel);
    virtual void collision();
    void setVisible(bool vis);
    bool toDelete;
    float HP;
    float MAX_HP;
    bool launched;
    bool bumped;

public slots:
    virtual void paintPixmap();

signals:
    void getPoint(int);
    void dead();

protected:
    b2World *world;
    b2Body *body;
    QGraphicsPixmapItem pixmap;
    QSizeF size;
    void burstTheGravity(b2Vec2 bodypos);
    QMainWindow *parent;

    static QSizeF world_meter;
    static QSizeF world_pixel;
};

#endif // GAMEITEM_H
