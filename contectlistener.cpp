#include "contectlistener.h"
#include <QDebug>

ContectListener::ContectListener()
{

}

void ContectListener::BeginContact(b2Contact *contact)
{
    //qDebug() << "Begin";

    /*if(contact->GetFixtureA()->GetBody()->GetType() == b2_dynamicBody) {
        void* temp = contact->GetFixtureA()->GetBody()->GetUserData();
        static_cast<GameItem*>(temp)->collision();
    }
    if(contact->GetFixtureB()->GetBody()->GetType() == b2_dynamicBody) {
        void* temp = contact->GetFixtureB()->GetBody()->GetUserData();
        static_cast<GameItem*>(temp)->collision();
    }*/
}

void ContectListener::EndContact(b2Contact *contact)
{
    //qDebug() << "End";
    static_cast<GameItem*>(contact->GetFixtureA()->GetBody()->GetUserData())->collision();
    static_cast<GameItem*>(contact->GetFixtureB()->GetBody()->GetUserData())->collision();
}

void ContectListener::PreSolve(b2Contact *contact, const b2Manifold *Manifold)
{
    //qDebug() << "Presolve";
}

void ContectListener::PostSolve(b2Contact *contact, const b2ContactImpulse *impulse)
{
    //qDebug() << "Postsolve" << impulse->normalImpulses[10];
}
