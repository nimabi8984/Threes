//
//  Commponent.hpp
//  TestCommponent
//
//  Created by CT on 11/24/15.
//  Copyright © 2015 CT. All rights reserved.
//

#ifndef Commponent_hpp
#define Commponent_hpp

#include <stdio.h>
#include <iostream>
#include <memory>
#include "Observer.hpp"
using namespace std;

class Commponent:public IObserver , public std::enable_shared_from_this<Commponent>
{
public:
	Commponent(const string &key);
	virtual ~Commponent();
    
    virtual void registerEvent(const string &name, eventFunc event) override;
    virtual void removeEvent(const string &name) override;
    virtual void dispatchEvent(const string &name, const Msg& msg = Msg()) override;
    inline const string& getKey() const {return _key;}
protected:
    
private:
    const std::string _key;
};

#endif /* Commponent_hpp */
