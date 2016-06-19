#include "planet.h"

Planet::Planet(float x, float y, float radius, b2World *world, QMainWindow *parent):GameItem(world, parent)
{
    b2BodyDef bdef;
    bdef.position.Set(x, y);
    bdef.type = b2_staticBody;
    bdef.bullet = true;
    bdef.userData = this;
    body = world->CreateBody(&bdef);

    b2CircleShape bodyshape;
    bodyshape.m_radius = radius;

    b2FixtureDef fixturedef;
    fixturedef.shape = &bodyshape;
    fixturedef.density = 5.0f;
    fixturedef.friction = 0.2f;
    fixturedef.restitution = 0.4f;
    body->SetAngularDamping(3);
    body->CreateFixture(&fixturedef);

    size.setHeight(radius*2);
    size.setWidth(radius*2);
}
