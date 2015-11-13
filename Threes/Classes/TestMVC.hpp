//
//  TestMVC.hpp
//  Threes
//
//  Created by CT on 11/12/15.
//
//

#ifndef TestMVC_hpp
#define TestMVC_hpp

#include <stdio.h>
#include <iostream>
#include "Common.hpp"
using namespace std;

class StartupCommand: public SimpleCommand
{
public:
    virtual void execute(INotification const& notification) override
    {
        CCLOG("Start ");
    }

};

class ExitCommand: public SimpleCommand
{
public:
    virtual void execute(INotification const& notification) override
    {
        CCLOG("End ");
    }
    
};

class ApplicationFacade
: public virtual IFacade
, public Facade
{
    friend class Facade;
public:
    static const string STARTUP;
    static const string EXIT;
protected:
    ApplicationFacade(void)
    : Facade(this, "ApplicationFacade")
    {
        initializeController();
    }
    
public:
    static ApplicationFacade& getInstance(void)
    {
        if (Facade::hasCore("ApplicationFacade"))
            return *(dynamic_cast<ApplicationFacade*>(&Facade::getInstance("ApplicationFacade")));
        return *(new ApplicationFacade());
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
        StartupCommand* startupCommand = new StartupCommand();
        registerCommand(STARTUP, startupCommand);
        ExitCommand* exitCommand = new ExitCommand();
        registerCommand(EXIT, exitCommand);
    }
    
    ~ApplicationFacade()
    {
    }
};
const string ApplicationFacade::STARTUP = "startup";
const string ApplicationFacade::EXIT = "exit";

#endif /* TestMVC_hpp */
