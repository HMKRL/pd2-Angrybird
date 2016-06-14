#ifndef CONTECTLISTENER_H
#define CONTECTLISTENER_H

#include "bird.h"
#include <Box2D/Box2D.h>

class ContectListener : public b2ContactListener
{
public:
    ContectListener();
    void BeginContact(b2Contact *contact);
    void EndContact(b2Contact *contact);
};

#endif // CONTECTLISTENER_H
