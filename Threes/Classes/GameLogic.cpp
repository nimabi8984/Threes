//
//  GameLogic.cpp
//  Threes
//
//  Created by CT on 11/25/15.
//
//

#include "GameLogic.hpp"
#include "CommponentManager.hpp"
#include "GameModel.hpp"
#include "Drop.hpp"

GameLogic::GameLogic()
:Commponent("GameLogic")
,_selectX(-1)
,_selectY(-1)
{

}

GameLogic::~GameLogic()
{
	
}

void GameLogic::setSelect(int x, int y)
{
    if (_selectX!=-1&&_selectY!=-1&&(x!=_selectX||y!=_selectY)) {
        GetCommponent<GameModel*>("GameModel")->exchange(_selectX, _selectY, x, y);
        _selectX = -1;
        _selectY = -1;
        Singleton<Drop>::getInstance().doEliminate();
        return;
    }
    _selectX = x;
    _selectY = y;
}