#ifndef TNT_H
#define TNT_H

#include "gameitem.h"

class TNT : public GameItem
{
public:
    TNT(float x, float y, float w, float h, float angle, b2World *world, QGraphicsScene *scene, QTimer *timer, QMainWindow *parent);
    virtual void collision();
};

#endif // TNT_H
