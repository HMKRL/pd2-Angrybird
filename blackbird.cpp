#include "blackbird.h"

blackBird::blackBird(float x, float y, float radius, QTimer *timer, b2World *world, QGraphicsScene *scene):
    Bird(x, y, radius, timer, world, scene)
{
    pixmap.setPixmap(QPixmap(":/image/res/BIRD_Black.png").scaled(radius*2*20, radius*2*20));
}

void blackBird::active()
{
    actived = true;
    qDebug() << "black active";

    b2Vec2 mypos = body->GetPosition();
    int bcnt = world->GetBodyCount();
    b2Body* blist= world->GetBodyList();
    qDebug() << bcnt;
    for(int i = 0;i < bcnt;++i) {
        float dis = qSqrt(qPow(blist->GetPosition().x - mypos.x, 2) + qPow(blist->GetPosition().y - mypos.y, 2));
        qDebug() << dis;
        if(dis < 2.5) static_cast<GameItem*>(blist->GetUserData())->toDelete = true;
        else if(dis < 8 && dis > 2.5) {
            blist->ApplyForceToCenter(b2Vec2((blist->GetPosition().x - mypos.x) * 1000, (blist->GetPosition().y - mypos.y) * 1000), true);
        }
        blist = blist->GetNext();
    }
}
