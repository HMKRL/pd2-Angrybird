#include "contectlistener.h"
#include <QDebug>

ContectListener::ContectListener()
{

}

void ContectListener::BeginContact(b2Contact *contact)
{
    if(contact->GetFixtureA()->GetBody()->GetType() == b2_dynamicBody) {
        void* temp = contact->GetFixtureA()->GetBody()->GetUserData();
        static_cast<Bird*>(temp)->crash();
    }
    if(contact->GetFixtureB()->GetBody()->GetType() == b2_dynamicBody) {
        void* temp = contact->GetFixtureB()->GetBody()->GetUserData();
        static_cast<Bird*>(temp)->crash();
    }
}

void ContectListener::EndContact(b2Contact *contact)
{

}
