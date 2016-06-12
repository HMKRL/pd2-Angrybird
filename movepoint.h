#ifndef MOVEPOINT_H
#define MOVEPOINT_H

#include <Box2D/Box2D.h>
#include <QSizeF>
#include <QPointF>

class MovePoint
{
public:
    MovePoint();
    static void setGlobalSize(QSizeF meter, QSizeF pixel);
    static QPointF meter2pixel(b2Vec2 body_pos, QSizeF body_meter);
    static QPointF pixel2meter(QPointF pos);

private:
    static QSizeF world_meter;
    static QSizeF world_pixel;
};

#endif // MOVEPOINT_H
