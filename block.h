#ifndef BLOCK_H
#define BLOCK_H

#define GLASS_HP 8000
#define WOOD_HP 12000
#define ROCK_HP 20000

#include "gameitem.h"
#include <QDebug>

class Block : public GameItem
{
public:
    Block(float x, float y, float w, float h, float angle, int type, b2World *world, QGraphicsScene *scene, QTimer *timer);
    virtual void collision();
    enum {Wood, Glass, Stone};

private:
    int Type;
    QString material, ratio;
    QSound *breakSound;
};

#endif // BLOCK_H
