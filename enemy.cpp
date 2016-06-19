#include "enemy.h"

Enemy::Enemy(float x, float y, float radius, float angle, QTimer *timer, b2World *world, QGraphicsScene *scene, QMainWindow *parent):GameItem(world, parent)
{
    b2BodyDef bdef;
    bdef.position.Set(x, y);
    bdef.type = b2_dynamicBody;
    bdef.bullet = true;
    bdef.userData = this;
    bdef.angle = angle*PI/180;
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

    MAX_HP = HP = 4000;
    connect(this, SIGNAL(dead()), parent, SLOT(enemyKilled()));
}

Enemy::~Enemy()
{
    emit dead();
}

void Enemy::collision()
{
    bumped = true;
    b2Vec2 speed = body->GetLinearVelocity();
    float Vpow2 = qPow(speed.x, 2) + qPow(speed.y, 2);

    HP = HP - Vpow2*40;
    if(HP <= 0) {
        toDelete = true;
        emit getPoint(5000);
    }
    if(HP / MAX_HP < 0.33)
        pixmap.setPixmap(QPixmap(":/image/res/PIG_03.png").scaled(size.width()*20, size.height()*20));
    else if(HP / MAX_HP < 0.66)
        pixmap.setPixmap(QPixmap(":/image/res/PIG_02.png").scaled(size.width()*20, size.height()*20));
    else
        pixmap.setPixmap(QPixmap(":/image/res/PIG.png").scaled(size.width()*20, size.height()*20));
}
