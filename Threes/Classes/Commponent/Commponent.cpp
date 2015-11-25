
//
//  Commponent.cpp
//  TestCommponent
//
//  Created by CT on 11/24/15.
//  Copyright © 2015 CT. All rights reserved.
//

#include "Commponent.hpp"
#include "CommponentManager.hpp"

Commponent::Commponent(const string &key)
:_key(key)
{
    CommponentManager::getInstance()->insert(_key, this);
}

Commponent::~Commponent()
{
    CommponentManager::getInstance()->remove(_key);
}

void Commponent::registerEvent(const string &name, eventFunc event)
{
    IObserver::registerEvent(name, event);
}

void Commponent::removeEvent(const string &name)
{
    IObserver::removeEvent(name);
}

void Commponent::dispatchEvent(const string &name, const Msg& msg)
{
    IObserver::dispatchEvent(name, msg);
}