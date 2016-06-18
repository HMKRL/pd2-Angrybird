#ifndef YELLOWBIRD_H
#define YELLOWBIRD_H

#include "bird.h"

class yellowBird : public Bird
{
public:
    yellowBird(float x, float y, float radius, QTimer *timer, b2World *world, QGraphicsScene *scene);
    virtual void active();
};

#endif // YELLOWBIRD_H
