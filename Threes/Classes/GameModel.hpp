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
#include "Commponent.hpp"

class GameModel:public Commponent {
    
private:
    Fruit_Ptr fruits[xCount][yCount];
    
    
private:
    void initRandomFruits();
    
public:
    GameModel(const std::string &key);
    ~GameModel() {}
    
    void init();
    
    inline Fruit_Ptr getFuit(int x, int y) { return fruits[x][y]; }
};

#endif /* GameModel_hpp */
