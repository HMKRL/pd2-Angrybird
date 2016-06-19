#ifndef CONTECTLISTENER_H
#define CONTECTLISTENER_H

#include "bird.h"
#include "gameitem.h"
#include <Box2D/Box2D.h>

class ContectListener : public b2ContactListener
{
public:
    ContectListener();
    void EndContact(b2Contact *contact);
};

#endif // CONTECTLISTENER_H
