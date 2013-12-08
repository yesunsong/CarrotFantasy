//
//  StaticsLayer.cpp
//  CarrotFantasy
//
//  Created by 叶孙松 on 13-12-8.
//
//

#include "StaticsLayer.h"

bool StaticsLayer::init(){
    if (!CCLayer::init()) {
        return false;
    }
    CCSprite *statistics_bg=CCSprite::createWithSpriteFrameName("statistics_bg.png");
    statistics_bg->setAnchorPoint(CCPointZero);
    addChild(statistics_bg);
    
    CCSprite *sp_statisticsBg_cn=CCSprite::createWithSpriteFrameName("statistics_bg_CN.png");
    sp_statisticsBg_cn->setAnchorPoint(CCPointZero);
    addChild(sp_statisticsBg_cn);
    return true;
}