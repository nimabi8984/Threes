//
//  Drop.hpp
//  Threes
//
//  Created by CT on 11/6/15.
//
//

#ifndef Drop_hpp
#define Drop_hpp

#include <stdio.h>
#include "Singleton.hpp"
#include <iostream>
#include <vector>
#include <Map>
#include <list>
#include <time.h>
#include <cstdio>
#include "Vec2.h"
#include "Const.h"
USING_NS_CC_MATH;

struct Range{
    int a,b;
    Range(int _a, int _b):a(_a),b(_b)
    {}
    void toString()
    {
        CCLOG("Range is %d-%d\n",a,b);
    }
    inline bool rangeIn(int num)
    {
        return num>=a && num<=b;
    }
    void setRangeDisable()
    {
        a = -1;
        b = -1;
    }
};

enum class Priority{
    THREE = 0x3,
    FOUR = 1<<3,
    CROSS = 1<<4,
    FIVE = 1<<5
};

class Threes {
private:
    std::vector<Vec2> _array;
    Vec2 _center;
    Priority prrority;
public:
    Threes(){}
    ~Threes(){}
    
    void addPoint(Vec2 &point)
    {
        _array.push_back(point);
    }
    
    void setCenter(Vec2 &center)
    {
        _center = center;
    }
};

using ThreesVec = std::vector<Threes *>;
using Nodes = std::list<Range *>;
using XYMap = std::map<int, Nodes *>;

class Drop {
private:
    int hMap[xCount][yCount];
    XYMap xVec, yVec;
    XYMap xx[2]{xVec, yVec};
    std::vector<Vec2 *> clashs;
    int _map[xCount][yCount];
    
private:
    void init();
    void threes();
    void processClashs();
    inline void processClash(int x, int y);
protected:
    Drop() {};
    ~Drop() {};
    
    friend class Singleton<Drop>;
public:
    void doEliminate();
    
};

#endif /* Drop_hpp */
