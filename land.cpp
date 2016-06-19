#include "land.h"

Land::Land(float x, float y, float w, float h, float angle, b2World *world, QMainWindow *parent):GameItem(world, parent)
{
    size = QSizeF(w, h);

    b2BodyDef bodyDef;
    bodyDef.userData = this;
    bodyDef.position.Set(x,y);
    bodyDef.angle = angle*PI/180;
    body = world->CreateBody(&bodyDef);
    b2PolygonShape bodyBox;
    bodyBox.SetAsBox(w,h);
    body->CreateFixture(&bodyBox, 9);
}
