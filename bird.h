#ifndef BIRD_H
#define BIRD_H

#include "gameitem.h"
#include <QDebug>

class Bird : public GameItem
{
public:
    Bird(float x, float y, float radius, QTimer *timer, b2World *world, QGraphicsScene *scene, QPixmap birdpix);
    Bird(QPointF pos, float radius, QTimer *timer, b2World *world, QGraphicsScene *scene, QPixmap birdpix);
    void setLinearVelocity(b2Vec2 velocity);
    void crash();
private:
    int HP;
};

#endif // BIRD_H
