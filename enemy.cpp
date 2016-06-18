#include "enemy.h"

Enemy::Enemy(float x, float y, float radius, QTimer *timer, b2World *world, QGraphicsScene *scene):GameItem(world)
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
    fixturedef.density = 5.0f;
    fixturedef.friction = 0.2f;
    fixturedef.restitution = 0.3f;
    body->SetAngularDamping(3);
    body->CreateFixture(&fixturedef);

    connect(timer, SIGNAL(timeout()), this, SLOT(paintPixmap()));

    pixmap.setPixmap(QPixmap(":/image/res/PIG.png").scaled(radius*2*20, radius*2*20));
    pixmap.setTransformOriginPoint(pixmap.boundingRect().width()/2,pixmap.boundingRect().height()/2);
    scene->addItem(&pixmap);

    size.setHeight(radius*2);
    size.setWidth(radius*2);

    HP = 4000;
}

void Enemy::collision()
{
    bumped = true;
    b2Vec2 speed = body->GetLinearVelocity();
    float Vpow2 = qPow(speed.x, 2) + qPow(speed.y, 2);

    HP = HP - Vpow2*40;
    if(HP <= 0) {
        toDelete = true;
    }
}
