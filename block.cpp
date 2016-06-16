#include "block.h"

Block::Block(float x, float y, float w, float h, float angle, int type, b2World *world, QGraphicsScene *scene, QTimer *timer):GameItem(world)
{
    b2BodyDef bdef;
    bdef.position.Set(x, y);
    bdef.type = b2_dynamicBody;
    bdef.bullet = true;
    bdef.userData = this;
    bdef.angle = angle*PI/180;
    body = world->CreateBody(&bdef);

    b2PolygonShape bodyshape;
    bodyshape.SetAsBox(w/2, h/2);

    b2FixtureDef fixturedef;
    fixturedef.shape = &bodyshape;
    fixturedef.density = 10.0f;
    fixturedef.friction = 0.2f;
    fixturedef.restitution = 0.3f;
    body->SetAngularDamping(3);
    body->CreateFixture(&fixturedef);

    connect(timer, SIGNAL(timeout()), this, SLOT(paintPixmap()));

    pixmap.setPixmap(QPixmap(":/image/res/BLOCK_WOOD_4X4_1.png").scaled(40, 40));
    pixmap.setTransformOriginPoint(pixmap.boundingRect().width()/2,pixmap.boundingRect().height()/2);
    scene->addItem(&pixmap);

    size.setHeight(w);
    size.setWidth(h);

    HP = 8763;
}

void Block::collision()
{
    b2Vec2 speed = body->GetLinearVelocity();
    float V = qSqrt(qPow(speed.x, 2) + qPow(speed.y, 2));
    qDebug() << "Block hit";
    qDebug() << "HP :" << HP << "->" << HP - 400 * V;
    HP = HP - 400 * V;
    if(HP <= 0) pixmap.setVisible(false);
}
