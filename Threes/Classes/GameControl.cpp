//
//  GameControl.cpp
//  Threes
//
//  Created by CT on 11/12/15.
//
//

#include "GameControl.hpp"
#include "HelloWorldScene.h"
USING_NS_CC;

void GameStartCmd::initResource()
{
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("assets/fruit.plist");
}

void GameStartCmd::execute(INotification const& notification)
{
    CCLOG("Game Start");
    initResource();
    
    Director::getInstance()->runWithScene(HelloWorld::createScene());
}

