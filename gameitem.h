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

#define PI 3.1415926

class GameItem : public QObject
{
    Q_OBJECT
public:
    GameItem(b2World *world);
    ~GameItem();
    static void setGlobalSize(QSizeF Meter, QSizeF Pixel);
    virtual void collision();
    bool toDelete;
    float HP;
    float MAX_HP;

public slots:
    void paintPixmap();

protected:
    b2World *world;
    b2Body *body;
    QGraphicsPixmapItem pixmap;
    QSizeF size;

    static QSizeF world_meter;
    static QSizeF world_pixel;

private:
    void burstTheGravity(b2Vec2 bodypos);
};

#endif // GAMEITEM_H
