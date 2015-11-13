//
//  Drop.cpp
//  Threes
//
//  Created by CT on 11/6/15.
//
//

#include "Drop.hpp"

void Drop::threes()
{
    memset(hMap, 0, sizeof(hMap));
    for (int i = 0; i < xCount; ++i)
    {
        int startPos[] = {0,0};
        int len[] = {1,1};
        static auto cpv = [&](int value, int startPosValue, int index, int j){
            if(j<yCount && startPosValue != 0 && value == startPosValue)
            {
                ++len[index];
            }
            else
            {
                if(len[index]>=3)
                {
                    CCLOG("%dThrees!!!%d\n",i,index);
                    auto tmpMap = xx[index].find(i);
                    if (tmpMap != xx[index].end()) {
                        tmpMap->second->push_back(new Range(startPos[index],j-1));
                    }
                    else
                    {
                        auto nodes = new Nodes();
                        nodes->push_back(new Range(startPos[index],j-1));
                        xx[index][i] = nodes;
                    }
                    for (int k=startPos[index]; k<j-1; k++) {
                        if (index == 0) {
                            hMap[i][k] += 1;
                            if (hMap[i][k]>1) {
                                clashs.push_back(new Vec2(i, k));
                            }
                        }
                        else {
                            hMap[k][i] += 1;
                            if (hMap[k][i]>1) {
                                clashs.push_back(new Vec2(k, i));
                            }
                        }
                    }
                }
                len[index] = 1;
                startPos[index] = j;
            }
        };
        for (int j = 1; j < yCount+1; ++j)  //  此处多访问了 一个数组纬度
        {
            cpv(_map[i][j], _map[i][startPos[0]], 0, j);
            cpv(_map[j][i], _map[startPos[1]][i], 1, j);
        }
    }
}

Range* findIndex(Nodes *array, int value)
{
    if (array == nullptr) {
        return nullptr;
    }
    for (auto range:*array) {
        if (range->rangeIn(value)) {
            return range;
        }
    }
    return nullptr;
}

// ***@*** 七连中间未处理
bool checkSelfIsTrible( int i, Range *range )
{
    if (i - range->a >= 3) {
        range->b = i-1;
        return false;
    }
    else if (range->b - i >= 3) {
        range->a = i+1;
        return false;
    }
    return false;
}

void Drop::processClash(int x, int y) {
    Range* xArray = findIndex(xx[0][x], y);
    Range* yArray = findIndex(xx[1][y], y);
    if (xArray && yArray) {
        int x1 = xArray->a, y1 = xArray->b;
        int x2 = yArray->a, y2 = yArray->b;
        xArray->setRangeDisable();
        yArray->setRangeDisable();
        for (int i=x1; i<y1; i++) {
            if (hMap[x][i] != 0) {
                processClash(x, i);
            }
            
        }
        for (int i=x2; i<y2; i++) {
            if (hMap[i][y] != 0) {
                processClash(i, y);
            }
        }
    }
    else if (xArray) {
        if (checkSelfIsTrible(x, xArray)) {
            xArray->setRangeDisable();
        }
    }
    else if (yArray) {
        if (checkSelfIsTrible(y, yArray)) {
            yArray->setRangeDisable();
        }
    }
}

void Drop::processClashs()
{
    for (auto clashP:clashs) {
        processClash(clashP->x, clashP->y);
    }
}

