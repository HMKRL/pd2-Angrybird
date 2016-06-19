#include "block.h"

Block::Block(float x, float y, float w, float h, float angle, int type, b2World *world, QGraphicsScene *scene, QTimer *timer, QMainWindow *parent):GameItem(world, parent)
{
    Type = type;
    if(Type == Wood) {
        material = "WOOD";
        MAX_HP = HP = WOOD_HP;
        breakSound = new QSound(":/sound/res/wood_break.wav");
    }
    else if(Type == Stone) {
        material = "ROCK";
        MAX_HP = HP = ROCK_HP;
        breakSound = new QSound(":/sound/res/stone_break.wav");
    }
    else if(Type == Glass) {
        material = "LIGHT";
        MAX_HP = HP = GLASS_HP;
        breakSound = new QSound(":/sound/res/glass_break.wav");
    }
    if(qFabs(w / h - 1)  < 10e-7) ratio = "4X4";
    if(qFabs(w / h - 0.1)  < 10e-7 || qFabs(w / h - 10) < 10e-7) ratio = "10X1";

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

    pixmap.setPixmap(QPixmap(":/image/res/BLOCK_"+material+"_"+ratio+"_1.png").scaled(w*20, h*20));
    pixmap.setTransformOriginPoint(pixmap.boundingRect().width()/2,pixmap.boundingRect().height()/2);
    scene->addItem(&pixmap);

    size.setHeight(h);
    size.setWidth(w);
}

void Block::collision()
{
    emit getPoint(139);
    bumped = true;
    b2Vec2 speed = body->GetLinearVelocity();
    float Vpow2 = qPow(speed.x, 2) + qPow(speed.y, 2);

    HP = HP - Vpow2*40;
    if(HP <= 0) {
        toDelete = true;
        breakSound->play();
        emit getPoint(502);
    }

    if(HP / MAX_HP < 0.2)
    pixmap.setPixmap(QPixmap(":/image/res/BLOCK_"+material+"_"+ratio+"_4.png").scaled(size.width()*20, size.height()*20));
    else if(HP / MAX_HP < 0.4)
    pixmap.setPixmap(QPixmap(":/image/res/BLOCK_"+material+"_"+ratio+"_3.png").scaled(size.width()*20, size.height()*20));
    else if(HP / MAX_HP < 0.6)
    pixmap.setPixmap(QPixmap(":/image/res/BLOCK_"+material+"_"+ratio+"_2.png").scaled(size.width()*20, size.height()*20));
    else if(HP / MAX_HP < 0.8)
    pixmap.setPixmap(QPixmap(":/image/res/BLOCK_"+material+"_"+ratio+"_1.png").scaled(size.width()*20, size.height()*20));
}
