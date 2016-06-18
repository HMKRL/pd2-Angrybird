#ifndef BLACKBIRD_H
#define BLACKBIRD_H

#include "bird.h"

class blackBird : public Bird
{
public:
    blackBird(float x, float y, float radius, QTimer *timer, b2World *world, QGraphicsScene *scene);
    virtual void active();
};

#endif // BLACKBIRD_H
