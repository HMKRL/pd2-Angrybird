#ifndef BIRD_H
#define BIRD_H

#include "gameitem.h"
#include "movepoint.h"
#include <QDebug>

class Bird : public GameItem
{
public:
    Bird(float x, float y, float radius, QTimer *timer, b2World *world, QGraphicsScene *scene, QMainWindow *parent);
    //Bird(QPointF pos, float radius, QTimer *timer, b2World *world, QGraphicsScene *scene);
    void setLinearVelocity(b2Vec2 velocity);
    virtual void collision();
    virtual void active();
    bool actived;
};

#endif // BIRD_H
