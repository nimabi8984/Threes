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
    
    
private:
    void initRandomFruits();
    
public:
    GameModel() {}
    ~GameModel() {}
    
    void init();
    
    inline Fruit_Ptr getFuit(int x, int y) { return fruits[x][y]; }
};

#endif /* GameModel_hpp */
