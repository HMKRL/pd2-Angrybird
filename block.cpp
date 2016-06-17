#include "block.h"

Block::Block(float x, float y, float w, float h, float angle, int type, b2World *world, QGraphicsScene *scene, QTimer *timer):GameItem(world)
{
    Type = type;
    if(Type == Wood) {
        material = "WOOD";
        MAX_HP = HP = WOOD_HP;
        breakSound = new QSound(":/sound/res/glass_break.wav");
    }
    else if(Type == Stone) {
        material = "ROCK";
        MAX_HP = HP = ROCK_HP;
        breakSound = new QSound(":/sound/res/glass_break.wav");
    }
    else if(Type == Glass) {
        material = "LIGHT";
        MAX_HP = HP = GLASS_HP;
        breakSound = new QSound(":/sound/res/glass_break.wav");
    }

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
    fixturedef.friction = 0.8f;
    fixturedef.restitution = 0.3f;
    body->SetAngularDamping(3);
    body->CreateFixture(&fixturedef);

    connect(timer, SIGNAL(timeout()), this, SLOT(paintPixmap()));

    pixmap.setPixmap(QPixmap(":/image/res/BLOCK_"+material+"_4X4_1.png").scaled(w*20, h*20));
    pixmap.setTransformOriginPoint(pixmap.boundingRect().width()/2,pixmap.boundingRect().height()/2);
    scene->addItem(&pixmap);

    size.setHeight(w);
    size.setWidth(h);
}

void Block::collision()
{
    b2Vec2 speed = body->GetLinearVelocity();
    float Vpow2 = qPow(speed.x, 2) + qPow(speed.y, 2);

    HP = HP - Vpow2*40;
    if(HP <= 0) {
        toDelete = true;
        breakSound->play();
    }
    qDebug() << "HP :" << HP << "->" << HP - Vpow2*40 << toDelete << MAX_HP << HP / MAX_HP;
    if(HP / MAX_HP < 0.2)
    pixmap.setPixmap(QPixmap(":/image/res/BLOCK_"+material+"_4X4_4.png").scaled(size.width()*20, size.height()*20));
    else if(HP / MAX_HP < 0.4)
    pixmap.setPixmap(QPixmap(":/image/res/BLOCK_"+material+"_4X4_3.png").scaled(size.width()*20, size.height()*20));
    else if(HP / MAX_HP < 0.6)
    pixmap.setPixmap(QPixmap(":/image/res/BLOCK_"+material+"_4X4_2.png").scaled(size.width()*20, size.height()*20));
    else if(HP / MAX_HP < 0.8)
    pixmap.setPixmap(QPixmap(":/image/res/BLOCK_"+material+"_4X4_1.png").scaled(size.width()*20, size.height()*20));
}
