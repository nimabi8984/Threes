//
//  Fruit.cpp
//  Threes
//
//  Created by CT on 11/6/15.
//
//

#include "Fruit.hpp"

Fruit::Fruit(FruitType type):
_x(0),
_y(0),
_sprite(nullptr),
_type(type)
{
    
}

Fruit::~Fruit()
{
    CCLOG("Fruit is destoryed!!");
//    CC_SAFE_DELETE(_sprite);
}

std::shared_ptr<Fruit> Fruit::create(FruitType type)
{
    auto fruit = std::make_shared<Fruit>(type);
    if (fruit->init()) {
        return fruit;
    }
    return nullptr;
}

bool Fruit::init()
{
    _sprite = ImageView::create(StringUtils::format("fruit_type_%d.png", (int)_type), Widget::TextureResType::PLIST);
    _sprite->setTouchEnabled(true);
    _sprite->addTouchEventListener([this](Ref* sender,Widget::TouchEventType type){
        if (type == Widget::TouchEventType::ENDED) {
            
        }
    });
    return true;
}

ImageView* Fruit::getSprite()
{
    return _sprite;
}