#ifndef ENEMY_H
#define ENEMY_H

#include <gameitem.h>

class Enemy : public GameItem
{
public:
    Enemy(float x, float y, float radius, QTimer *timer, b2World *world, QGraphicsScene *scene, QMainWindow *parent);
    ~Enemy();
    virtual void collision();
};

#endif // ENEMY_H
