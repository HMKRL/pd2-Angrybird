#ifndef LAND_H
#define LAND_H

#define x_0 144
#define y_0 490
#define PI 3.1415926

#include "gameitem.h"
#include <QDebug>

class Land : public GameItem
{
public:
    Land(float x, float y, float w, float h, float angle, b2World *world);
};

#endif // LAND_H
