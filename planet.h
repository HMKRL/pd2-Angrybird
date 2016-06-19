#ifndef PLANET_H
#define PLANET_H

#include "gameitem.h"

class Planet : public GameItem
{
public:
    Planet(float x, float y, float radius, b2World *world, QMainWindow *parent);
};

#endif // PLANET_H
