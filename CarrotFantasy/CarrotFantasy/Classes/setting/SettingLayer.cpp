//
//  SettingLayer.cpp
//  CarrotFantasy
//
//  Created by 叶孙松 on 13-12-8.
//
//

#include "SettingLayer.h"

bool SettingLayer::init(){
    if (!CCLayer::init()) {
        return false;
    }
    CCPoint point=ccp(150,150);
    winSize=CCDirector::sharedDirector()->getWinSize();
    
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("setting01-hd.plist");
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("setting02-hd.plist");
   
    CCSprite *setting_bg=CCSprite::createWithSpriteFrameName("setting_bg.png");
    setting_bg->setAnchorPoint(CCPointZero);
    addChild(setting_bg);
    
    CCSprite *sp_settingBg_cn=CCSprite::createWithSpriteFrameName("setting_bg_CN.png");
    sp_settingBg_cn->setAnchorPoint(CCPointZero);
    addChild(sp_settingBg_cn);
    
    CCControlButton *resetgameBtn=createButton("resetgame_normal_CN.png","resetgame_pressed_CN.png");//重置
    resetgameBtn->setPosition(point);
    addChild(resetgameBtn);
    
	CCControlButton *soundfxBtn=createButton("soundfx_off_CN.png","soundfx_on_CN.png");//声音
    soundfxBtn->setPosition(point);
    addChild(soundfxBtn);
    
    CCControlButton *bgmusicBtn=createButton("bgmusic_off_CN.png","bgmusic_on_CN.png");//音效
    bgmusicBtn->setPosition(point);
    addChild(bgmusicBtn);
    
    return true;
}

CCControlButton * SettingLayer::createButton(const char *normal,const char *pressed){
    CCScale9Sprite* pressSprite= CCScale9Sprite::createWithSpriteFrameName(pressed);
    CCControlButton *button=CCControlButton::create(CCScale9Sprite::createWithSpriteFrameName(normal));
    button->setBackgroundSpriteForState(pressSprite, CCControlStateHighlighted);
    button->setPreferredSize(CCSizeMake(pressSprite->getContentSize().width, pressSprite->getContentSize().height));
    return button;
}

//CCControlButton *achievementsBtn=createButton("achievements_normal_CN.png","achievements_pressed_CN.png");//成就
//achievementsBtn->setPosition(point);
//    addChild(achievementsBtn);

//CCControlButton *gamecenterBtn=createButton( "gamecenter_off_CN.png","gamecenter_on_CN.png");//gamecenter
//gamecenterBtn->setPosition(point);
//    addChild(gamecenterBtn);

//CCControlButton *icloudBtn=createButton("icloud_normal_CN.png","icloud_pressed_CN.png");//icloud
//icloudBtn->setPosition(point);
//    addChild(icloudBtn);

//CCControlButton *languageBtn=createButton("language_normal_CN.png","language_pressed_CN.png");//正体中文语言
//languageBtn->setPosition(point);
//    addChild(languageBtn);

//CCControlButton *leaderboradBtn=createButton("leaderborad_normal_CN.png","leaderborad_pressed_CN.png");//排行榜
//leaderboradBtn->setPosition(point);
//    addChild(leaderboradBtn);