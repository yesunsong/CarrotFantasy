//
//  CreditsLayer.cpp
//  CarrotFantasy
//
//  Created by 叶孙松 on 13-12-8.
//
//

#include "CreditsLayer.h"

bool CreditsLayer::init(){
    if (!CCLayer::init()) {
        return false;
    }
    CCSprite *credits_bg=CCSprite::createWithSpriteFrameName("credits_bg.png");
    credits_bg->setAnchorPoint(CCPointZero);
    addChild(credits_bg);
    return true;
}