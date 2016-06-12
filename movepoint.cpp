#include "movepoint.h"
#include <QDebug>

MovePoint::MovePoint()
{
}

QSizeF MovePoint::world_meter = QSizeF();
QSizeF MovePoint::world_pixel = QSizeF();

void MovePoint::setGlobalSize(QSizeF meter, QSizeF pixel)
{
    world_meter = meter;
    world_pixel = pixel;
}

QPointF MovePoint::meter2pixel(b2Vec2 body_pos, QSizeF body_meter)
{
    QPointF pos;
    pos.setX(((body_pos.x - body_meter.width() / 2) / world_meter.width()) * world_pixel.width());
    pos.setY((1.0f - ((body_pos.y + body_meter.height() / 2) / world_meter.height())) * world_pixel.height());
    return pos;
}

QPointF MovePoint::pixel2meter(QPointF pos)
{
    QPointF out;
    out.setX((pos.x() / world_pixel.width()) * world_meter.width());
    out.setY((1.0f - pos.y() / world_pixel.height()) * world_meter.height());
    return out;
}
