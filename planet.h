#ifndef PLANET_H
#define PLANET_H

#include "gameitem.h"

class Planet : public GameItem
{
public:
    Planet(float x, float y, float radius, b2World *world);
};

#endif // PLANET_H
