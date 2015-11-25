//
//  Observer.cpp
//  TestCommponent
//
//  Created by CT on 11/25/15.
//  Copyright © 2015 CT. All rights reserved.
//

#include "Observer.hpp"

IObserver::IObserver()
{

}

IObserver::~IObserver()
{
    _events.clear();
}

void IObserver::registerEvent(const string &name, eventFunc event)
{
    _events.insert(make_pair(name, event));
}

void IObserver::removeEvent(const string &name)
{
    _events.erase(name);
}

void IObserver::dispatchEvent(const string &name)
{
    auto event = _events.find(name);
    if (event!=_events.end()) {
        event->second(Msg());
    }
}