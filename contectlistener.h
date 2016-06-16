#ifndef CONTECTLISTENER_H
#define CONTECTLISTENER_H

#include "bird.h"
#include "gameitem.h"
#include <Box2D/Box2D.h>

class ContectListener : public b2ContactListener
{
public:
    ContectListener();
    void BeginContact(b2Contact *contact);
    void EndContact(b2Contact *contact);
    void PreSolve(b2Contact *contact, const b2Manifold *Manifold);
    void PostSolve(b2Contact *contact, const b2ContactImpulse *impulse);
};

#endif // CONTECTLISTENER_H
