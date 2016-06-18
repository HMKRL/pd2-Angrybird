#include "yellowbird.h"

b2Vec2 operator *(b2Vec2 V, float scalar) {
    return b2Vec2(V.x * scalar, V.y * scalar);
}

yellowBird::yellowBird(float x, float y, float radius, QTimer *timer, b2World *world, QGraphicsScene *scene):
    Bird(x, y, radius, timer, world, scene)
{
    pixmap.setPixmap(QPixmap(":/image/res/yellow_bird.png").scaled(radius*2*20, radius*2*20));
}

void yellowBird::active()
{
    actived = true;
    qDebug() << "yellow active";

    body->SetLinearVelocity(body->GetLinearVelocity() * 3);
}
