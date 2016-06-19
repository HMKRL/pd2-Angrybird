#include "flappybird.h"

flappyBird::flappyBird(float x, float y, float radius, QTimer *timer, b2World *world, QGraphicsScene *scene, QMainWindow *parent):
    Bird(x, y, radius, timer, world, scene, parent)
{
    pixmap.setPixmap(QPixmap(":/image/res/flappy.png").scaled(radius*2*20, radius*2*20));
}

void flappyBird::active()
{
    QSound::play(":/sound/res/flap.wav");
    b2Vec2 bodypos = body->GetPosition();
    float dist = qSqrt(qPow(bodypos.x - 39.75, 2) + qPow(bodypos.y - 18.7, 2));
    if(dist < 25.55) {
        b2Vec2 antigravity = b2Vec2(-(39.75 - bodypos.x) / dist * 10000, -(18.7 - bodypos.y) / dist * 10000);
        body->ApplyForceToCenter(antigravity, true);
    }
}
