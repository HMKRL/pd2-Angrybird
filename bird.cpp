#include "bird.h"

Bird::Bird(float x, float y, float radius, QTimer *timer, b2World *world, QGraphicsScene *scene):GameItem(world)
{
    launched = false;
    actived = false;
    b2BodyDef bdef;
    bdef.position.Set(x, y);
    bdef.type = b2_dynamicBody;
    bdef.bullet = true;
    bdef.userData = this;
    body = world->CreateBody(&bdef);

    b2CircleShape bodyshape;
    bodyshape.m_radius = radius;

    b2FixtureDef fixturedef;
    fixturedef.shape = &bodyshape;
    fixturedef.density = 5.0f;
    fixturedef.friction = 0.2f;
    fixturedef.restitution = 0.3f;
    body->SetAngularDamping(3);
    body->CreateFixture(&fixturedef);

    connect(timer, SIGNAL(timeout()), this, SLOT(paintPixmap()));

    pixmap.setPixmap(QPixmap(":/image/res/Normal_Bird.png").scaled(radius*2*20, radius*2*20));
    pixmap.setTransformOriginPoint(pixmap.boundingRect().width()/2,pixmap.boundingRect().height()/2);
    scene->addItem(&pixmap);

    size.setHeight(radius*2);
    size.setWidth(radius*2);

    setVisible(false);

    HP = 0xc8763; //Star Burst Stream
}
/*
Bird::Bird(QPointF pos, float radius, QTimer *timer, b2World *world, QGraphicsScene *scene):GameItem(world)
{
    launched = false;
    b2BodyDef bdef;
    bdef.position.Set(pos.x(), pos.y());
    bdef.type = b2_dynamicBody;
    bdef.bullet = true;
    bdef.userData = this;
    body = world->CreateBody(&bdef);

    b2CircleShape bodyshape;
    bodyshape.m_radius = radius;

    b2FixtureDef fixturedef;
    fixturedef.shape = &bodyshape;
    fixturedef.density = 8.0f;
    fixturedef.friction = 0.2f;
    fixturedef.restitution = 0.4f;
    body->SetAngularDamping(3);
    body->CreateFixture(&fixturedef);

    connect(timer, SIGNAL(timeout()), this, SLOT(paintPixmap()));

    pixmap.setPixmap(QPixmap(":/image/res/Normal_Bird.png").scaled(40, 40));
    pixmap.setTransformOriginPoint(pixmap.boundingRect().width()/2,pixmap.boundingRect().height()/2);
    scene->addItem(&pixmap);

    size.setHeight(radius*2);
    size.setWidth(radius*2);

    setVisible(false);

    HP = 0xc8763;
}
*/
void Bird::setLinearVelocity(b2Vec2 velocity)
{
    body->SetLinearVelocity(velocity);
}

void Bird::collision()
{
    bumped = true;
}

void Bird::active()
{
    actived = true;
    qDebug() << "active";
}
