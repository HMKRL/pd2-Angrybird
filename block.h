#ifndef BLOCK_H
#define BLOCK_H

#include "gameitem.h"
#include <QDebug>

class Block : public GameItem
{
public:
    Block(float x, float y, float w, float h, float angle, int type, b2World *world, QGraphicsScene *scene, QTimer *timer);
    virtual void collision();
    enum {Wood, Glass, Stone};
};

#endif // BLOCK_H
