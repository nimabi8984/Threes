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
#include "Common.hpp"

USING_NS_CC;

class GameMediator: public Mediator, public virtual IMediator{
  
public:
    
};

class GameView: public Layer{

private:
    std::vector<Fruit_Ptr> fruitVec;
    
public:
    GameView();
    ~GameView();
    
    bool init() override;
    
    
    
    CREATE_FUNC(GameView);
};

#endif /* GameView_h */
