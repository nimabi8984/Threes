
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

GameView::GameView()
{
    
}

GameView::~GameView()
{
    
}

bool GameView::init()
{
    for (int i=0; i<xCount; i++) {
        for (int j=0; j<yCount; j++) {
            auto type = (int)(CCRANDOM_0_1()*10);
            auto fruit = FruitFactory::getInstance()->getFruitByType(FruitType(type%6 + 1));
            fruitVec.push_back(fruit);
            auto sp = fruit->getSprite();
            this->addChild(sp);
            sp->setPosition(Point(i*Width+Width/2 , j*Height+Height/2));
        }
    }
    return true;
}