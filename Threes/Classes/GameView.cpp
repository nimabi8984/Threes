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

GameView::GameView(GameModel gm)
:_gm(nullptr)
{

}

GameView::~GameView()
{
    
}

GameView* GameView::create(GameModel gm)
{
    auto obj = new(std::nothrow) GameView(gm);
    if (obj && obj->init()) {
        obj->autorelease();
        return obj;
    }
    else{
        delete obj;
        obj = nullptr;
        return nullptr;
    }
}

bool GameView::init()
{
    auto bg = Sprite::create("assets/323.jpg");
    this->addChild(bg);
    auto size = Director::getInstance()->getWinSize();
    bg->setPosition(size.width/2, size.height/2);
    
    for (int i=0; i<xCount; i++) {
        for (int j=0; j<yCount; j++) {
            auto fruit = _gm->getFuit(i, j);
            auto sp = fruit->getSprite();
            this->addChild(sp);
            sp->setPosition(Point(i*Width+Width/2 , j*Height+Height/2));
        }
    }
    return true;
}