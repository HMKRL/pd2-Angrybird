#include "gameitem.h"
#include "movepoint.h"
#include <QDebug>

GameItem::GameItem(b2World *world, QMainWindow *p):world(world), body(NULL)
{
    toDelete = false;
    launched = false;
    bumped = false;
    parent = p;
    connect(this, SIGNAL(getPoint(int)), parent, SLOT(getScore(int)));
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
    emit getPoint(87);
}

void GameItem::setVisible(bool vis)
{
    pixmap.setVisible(vis);
    body->GetFixtureList()->SetSensor(!vis);
}

void GameItem::paintPixmap()
{
    b2Vec2 bodypos = body->GetPosition();
    QPointF pos = MovePoint::meter2pixel(bodypos, size);
    pixmap.setPos(pos.x(), pos.y());
    pixmap.setRotation(-body->GetAngle()*180/PI);
    burstTheGravity(bodypos);
    if((bodypos.x > 64 || bodypos.x < 0)||(bodypos.y > 40 || bodypos.y < 0)) toDelete = true;
    if(HP == 0xc8763) {
        b2Vec2 speed = body->GetLinearVelocity();
        if(qFabs(speed.x) < 10e-7 && qFabs(speed.y) < 10e-7 && launched) {
            toDelete = true;
        }
    }
    //qDebug() << bodypos.x << bodypos.y;
}

void GameItem::burstTheGravity(b2Vec2 bodypos)
{
    float dist = qSqrt(qPow(bodypos.x - 39.75, 2) + qPow(bodypos.y - 18.7, 2));
    if(dist < 25.55) {
        b2Vec2 gravity = b2Vec2((39.75 - bodypos.x) / dist * 100, (18.7 - bodypos.y) / dist * 100);
        body->ApplyForceToCenter(gravity, true);
    }
}
