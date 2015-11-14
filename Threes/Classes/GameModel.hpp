//
//  GameModel.hpp
//  Threes
//
//  Created by CT on 11/12/15.
//
//

#ifndef GameModel_hpp
#define GameModel_hpp

#include <stdio.h>
#include "Fruit.hpp"
#include "Const.h"

class GameModel {
    
private:
    Fruit_Ptr fruits[xCount][yCount];
public:
    GameModel() {}
    ~GameModel() {}
    
    void initRandomFruits();
};

#endif /* GameModel_hpp */
