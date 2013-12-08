//
//  ButtonLayer.cpp
//  CarrotFantasy
//
//  Created by 叶孙松 on 13-12-8.
//
//

#include "ButtonLayer.h"

bool ButtonLayer::init(){
    if (!CCLayer::init()) {
        return false;
    }
    CCPoint point=ccp(150,150);
    //    菜单层
    CCControlButton *homeBtn=createButton("setting_home_normal.png","setting_home_pressed.png");//主页
    homeBtn->setPosition(point);
    addChild(homeBtn);
    
    CCControlButton *optionsBtn=createButton("options_normal_CN.png","options_selected_CN.png");//选项
    optionsBtn->setPosition(point);
    addChild(optionsBtn);
    
    CCControlButton *statisticsBtn=createButton( "statistics_normal_CN.png","statistics_selected_CN.png");//统计
    statisticsBtn->setPosition(point);
    addChild(statisticsBtn);
    
    CCControlButton *creditsBtn=createButton( "credits_normal_CN.png","credits_selected_CN.png");//制作方
    creditsBtn->setPosition(point);
    addChild(creditsBtn);
    
    return true;
}

CCControlButton * ButtonLayer::createButton(const char *normal,const char *pressed){
    CCScale9Sprite* pressSprite= CCScale9Sprite::createWithSpriteFrameName(pressed);
    CCControlButton *button=CCControlButton::create(CCScale9Sprite::createWithSpriteFrameName(normal));
    button->setBackgroundSpriteForState(pressSprite, CCControlStateHighlighted);
    button->setPreferredSize(CCSizeMake(pressSprite->getContentSize().width, pressSprite->getContentSize().height));
    return button;
}