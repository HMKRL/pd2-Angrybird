#include "gameitem.h"
#include "movepoint.h"
#include <QDebug>

GameItem::GameItem(b2World *world):world(world), body(NULL)
{
}

GameItem::~GameItem()
{
    world->DestroyBody(body);
}

QSizeF GameItem::world_meter = QSizeF();
QSizeF GameItem::world_pixel = QSizeF();

void GameItem::setGlobalSize(QSizeF Meter, QSizeF Pixel)
{
    world_meter = Meter;
    world_pixel = Pixel;
}

void GameItem::collision()
{
    qDebug() << "Base hit";
}

void GameItem::paintPixmap()
{
    b2Vec2 bodypos = body->GetPosition();
    QPointF pos = MovePoint::meter2pixel(bodypos, size);
    pixmap.setPos(pos.x(), pos.y());
    pixmap.setRotation(-body->GetAngle()*180/PI);
    burstTheGravity(bodypos);
}

void GameItem::burstTheGravity(b2Vec2 bodypos)
{
    float dist = qSqrt(qPow(bodypos.x - 39.75, 2) + qPow(bodypos.y - 18.7, 2));
    if(dist < 25.55) {
        b2Vec2 gravity = b2Vec2((39.75 - bodypos.x) / dist * 140, (18.7 - bodypos.y) / dist * 140);
        body->ApplyForceToCenter(gravity, true);
    }
}
