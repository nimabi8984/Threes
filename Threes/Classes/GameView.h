//
//  GameView.h
//  Threes
//
//  Created by CT on 11/6/15.
//
//

#ifndef GameView_h
#define GameView_h

#include <stdio.h>
#include "cocos2d.h"
#include "Fruit.hpp"
#include <vector>
#include "GameModel.hpp"

USING_NS_CC;

class GameView: public Layer{

private:
    std::vector<Fruit_Ptr> fruitVec;
    GameModel* _gm;
    
public:
    GameView(GameModel gm);
    GameView() {}
    ~GameView();
    
    bool init() override;
    
    CREATE_FUNC(GameView);
    static GameView* create(GameModel gm);
};

#endif /* GameView_h */
