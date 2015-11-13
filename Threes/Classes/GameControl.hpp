//
//  GameControl.hpp
//  Threes
//
//  Created by CT on 11/12/15.
//
//

#ifndef GameControl_hpp
#define GameControl_hpp

#include <stdio.h>
#include "Singleton.hpp"
#include "Common.hpp"

class GameStartCmd: public SimpleCommand {

public:
    void initResource();
    
    virtual void execute(INotification const& notification) override;
};

#endif /* GameControl_hpp */
