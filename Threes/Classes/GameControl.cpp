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

GameController::GameController()
:_gameModel(nullptr)
,_gameView(nullptr)
{
    
}

GameController::~GameController()
{
    CC_SAFE_DELETE(_gameModel);
    CC_SAFE_DELETE(_gameView);
}

void GameController::gameStart()
{
    _gameModel = new GameModel();
    _gameModel->init();
    _gameView = new GameView();
    _gameView->setGameModel(_gameModel);
}

