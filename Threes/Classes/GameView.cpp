//
//  GameView.c
//  Threes
//
//  Created by CT on 11/6/15.
//
//

#include "GameView.h"
#include "Const.h"
#include "FruitFactory.hpp"
#include "Drop.hpp"
#include "CommponentManager.hpp"

GameView::~GameView()
{
    
}

bool GameView::init()
{
    auto bg = Sprite::create("assets/323.jpg");
    this->addChild(bg);
    auto size = Director::getInstance()->getWinSize();
    bg->setPosition(size.width/2, size.height/2);
    
    GetCommponent<GameModel*>("GameModel")->registerEvent(GameModel::EVENT_EXCHANGE, [](const Msg &msg){
        for (int i=0; i<xCount; i++) {
            for (int j=0; j<yCount; j++) {
                auto fruit = GetCommponent<GameModel*>("GameModel")->getFuit(i, j);
                auto sp = fruit->getSprite();
                sp->setPosition(Point(i*Width+Width/2 , j*Height+Height/2));
            }
        }
    });
    for (int i=0; i<xCount; i++) {
        for (int j=0; j<yCount; j++) {
            auto fruit = GetCommponent<GameModel*>("GameModel")->getFuit(i, j);
            auto sp = fruit->getSprite();
            this->addChild(sp);
            sp->setPosition(Point(i*Width+Width/2 , j*Height+Height/2));
        }
    }
    return true;
}