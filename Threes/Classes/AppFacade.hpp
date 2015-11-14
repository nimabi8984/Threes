//
//  AppFcade.hpp
//  Threes
//
//  Created by CT on 11/13/15.
//
//

#ifndef AppFacade_hpp
#define AppFacade_hpp

#include <stdio.h>
#include "Common.hpp"
#include <iostream>
#include "GameControl.hpp"

using namespace std;
//TODO virtual public 继承
class AppFacade: public Facade, public virtual IFacade {
    friend class Facade;
public:
    static const string START;
    
protected:
    AppFacade(void)
    : Facade(this, "AppFacade")
    {
        initializeController();
    }
    
public:
    static AppFacade& getInstance(void)
    {
        if (Facade::hasCore("AppFacade"))
            return *(dynamic_cast<AppFacade*>(&Facade::getInstance("AppFacade")));
        return *(new AppFacade());
    }
    
protected:
    virtual void initializeNotifier(string const& key)
    {
        Facade::initializeNotifier(key);
    }
    virtual void initializeFacade()
    {
        Facade::initializeFacade();
    }
    
    virtual void initializeController(void)
    {
        Facade::initializeController();
        auto start = new GameStartCmd();
        registerCommand(START, start);
    }
    
    ~AppFacade()
    {
    }
    
};

#endif /* AppFacade_hpp */
