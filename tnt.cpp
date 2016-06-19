#include "tnt.h"

TNT::TNT(float x, float y, float w, float h, float angle, b2World *world, QGraphicsScene *scene, QTimer *timer, QMainWindow *parent):GameItem(world, parent)
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
    fixturedef.density = 5.0f;
    fixturedef.friction = 1.0f;
    fixturedef.restitution = 0.3f;
    body->SetAngularDamping(3);
    body->CreateFixture(&fixturedef);

    connect(timer, SIGNAL(timeout()), this, SLOT(paintPixmap()));

    pixmap.setPixmap(QPixmap(":/image/res/BLOCK_EXTRA_TNT.png").scaled(w*20, h*20));
    pixmap.setTransformOriginPoint(pixmap.boundingRect().width()/2,pixmap.boundingRect().height()/2);
    scene->addItem(&pixmap);

    size.setHeight(h);
    size.setWidth(w);

    HP = 8000;
}

void TNT::collision()
{
    if(qSqrt(qPow(body->GetLinearVelocity().x, 2) + qPow(body->GetLinearVelocity().y, 2)) >= 1.3) {
        QSound::play(":/sound/res/BOOM.wav");
        b2Vec2 mypos = body->GetPosition();
        int bcnt = world->GetBodyCount();
        b2Body* blist= world->GetBodyList();
        for(int i = 0;i < bcnt;++i, blist = blist->GetNext()) {
            if(blist == body) continue;

            float dis = qSqrt(qPow(blist->GetPosition().x - mypos.x, 2) + qPow(blist->GetPosition().y - mypos.y, 2));
            if(dis < 8) {
                blist->ApplyForceToCenter(b2Vec2((blist->GetPosition().x - mypos.x) * 1000, (blist->GetPosition().y - mypos.y) * 1000), true);
            }
        }
        this->toDelete = true;
    }
    else QSound::play(":/sound/res/SSssss.wav");
}
