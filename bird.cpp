#include "bird.h"

Bird::Bird(float x, float y, float radius, QTimer *timer, b2World *world, QGraphicsScene *scene, QPixmap birdpix):GameItem(world)
{
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
    fixturedef.density = 10.0f;
    fixturedef.friction = 0.2f;
    fixturedef.restitution = 0.3f;
    body->SetAngularDamping(3);
    body->CreateFixture(&fixturedef);

    connect(timer, SIGNAL(timeout()), this, SLOT(paintPixmap()));

    pixmap.setPixmap(birdpix.scaled(radius*2*20, radius*2*20));
    pixmap.setTransformOriginPoint(pixmap.boundingRect().width()/2,pixmap.boundingRect().height()/2);
    scene->addItem(&pixmap);

    size.setHeight(radius*2);
    size.setWidth(radius*2);

    HP = 8763;
}

Bird::Bird(QPointF pos, float radius, QTimer *timer, b2World *world, QGraphicsScene *scene, QPixmap birdpix):GameItem(world)
{
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

    pixmap.setPixmap(birdpix.scaled(40, 40));
    pixmap.setTransformOriginPoint(pixmap.boundingRect().width()/2,pixmap.boundingRect().height()/2);
    scene->addItem(&pixmap);

    size.setHeight(radius*2);
    size.setWidth(radius*2);

    HP = 8763;
}

void Bird::setLinearVelocity(b2Vec2 velocity)
{
    body->SetLinearVelocity(velocity);
}

void Bird::collision()
{
    /*b2Vec2 speed = body->GetLinearVelocity();
    float V = qSqrt(qPow(speed.x, 2) + qPow(speed.y, 2));
    qDebug() << "Bird hit";
    qDebug() << "HP :" << HP << "->" << HP - 200 * V;
    HP = HP - 200 * V;
    if(HP <= 0) pixmap.setVisible(false);*/
}
