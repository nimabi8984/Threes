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

GameLogic::GameLogic()
:Commponent("GameLogic")
,_selectX(-1)
,_selectY(-1)
{

}

GameLogic::~GameLogic()
{
	
}

void eliminateRange(int line, int start, int end, bool isy = false)
{
    for (int i=start; i<=end; i++) {
        isy?GetCommponent<GameModel*>("GameModel")->eliminateFruit(i, line):GetCommponent<GameModel*>("GameModel")->eliminateFruit(line, i);
    }
}

void GameLogic::processEliminate(ThreesVec_ptr threeVec)
{
    for (auto three:*threeVec) {
        switch (three->prrority) {
            case Priority::FIVE:
                CCLOG("FIVE");
            case Priority::FOUR:
                CCLOG("FOUR");
            case Priority::THREE:
                CCLOG("THREE");
            case Priority::CROSS:
                CCLOG("CROSS");
            default:
                if (three->xLine != -1) {
                    eliminateRange(three->xLine, three->xstart, three->xend);
                }
                if (three->yLine != -1) {
                    eliminateRange(three->yLine, three->ystart, three->yend, true);
                }
                break;
        }
    }
}

void GameLogic::setSelect(int x, int y)
{
    if (_selectX!=-1&&_selectY!=-1&&(x!=_selectX||y!=_selectY)) {
        GetCommponent<GameModel*>("GameModel")->exchange(_selectX, _selectY, x, y);
        _selectX = -1;
        _selectY = -1;
        processEliminate(Singleton<Drop>::getInstance().doEliminate());
        return;
    }
    _selectX = x;
    _selectY = y;
}