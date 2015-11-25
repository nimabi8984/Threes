//
//  GameModel.cpp
//  Threes
//
//  Created by CT on 11/12/15.
//
//

#include "GameModel.hpp"
#include "FruitFactory.hpp"

GameModel::GameModel(const std::string &key):Commponent(key)
{
    init();
}

void GameModel::initRandomFruits()
{
    for (int i=0; i<xCount; i++) {
        for (int j=0; j<yCount; j++) {
            auto type = (int)(CCRANDOM_0_1()*10);
            auto fruit = FruitFactory::getInstance()->getFruitByType(FruitType(type%6 + 1));
            fruit->setXY(i, j);
            fruits[i][j] = fruit;
        }
    }
}

void GameModel::init()
{
    initRandomFruits();
}