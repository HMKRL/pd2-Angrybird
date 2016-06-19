#ifndef FLAPPYBIRD_H
#define FLAPPYBIRD_H

#include "bird.h"

class flappyBird : public Bird
{
public:
    flappyBird(float x, float y, float radius, QTimer *timer, b2World *world, QGraphicsScene *scene, QMainWindow *parent);
    virtual void active();
};

#endif // FLAPPYBIRD_H
