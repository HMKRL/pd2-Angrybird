#include "blackbird.h"

blackBird::blackBird(float x, float y, float radius, QTimer *timer, b2World *world, QGraphicsScene *scene, QMainWindow *parent):
    Bird(x, y, radius, timer, world, scene, parent)
{
    pixmap.setPixmap(QPixmap(":/image/res/BIRD_Black.png").scaled(radius*2*20, radius*2*20));
}

void blackBird::active()
{
    actived = true;
    qDebug() << "black active";
    QSound::play(":/sound/res/explosion.wav");
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
}
