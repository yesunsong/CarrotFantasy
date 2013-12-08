//
//  MainLayer.cpp
//  CarrotFantasy
//
//  Created by 叶孙松 on 13-12-8.
//
//

#include "MainLayer.h"

bool MainLayer::init(){
    if (!CCLayer::init()) {
        return false;
    }
       CCPoint point=ccp(150,150);
    winSize=CCDirector::sharedDirector()->getWinSize();
    
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("mainscene1-hd.plist");
    //背景层
    CCSprite *sp_bigBg=CCSprite::createWithSpriteFrameName("mainbg.png");//mainbg
    sp_bigBg->setPosition(CCPointZero);
    sp_bigBg->setAnchorPoint(CCPointZero);
    addChild(sp_bigBg);
    
    //中间层
    CCSprite *sp_bird=CCSprite::createWithSpriteFrameName("bird.png");
    sp_bird->setPosition(ccpAdd(point, ccp(0, 350)));
    addChild(sp_bird);

    CCMoveBy *moveTo=CCMoveBy::create(1.5,ccp(0,30));
    CCSequence *sequence=CCSequence::create(moveTo,moveTo->reverse(),NULL);
    CCRepeatForever *repeatForever=CCRepeatForever::create(static_cast<CCSequence *>(sequence));
    sp_bird->runAction(repeatForever);
    
    CCSprite *sp_cloud1=CCSprite::createWithSpriteFrameName("cloud1.png");//cloud1
    sp_cloud1->setPosition(ccpAdd(point, ccp(150, 300)));
    addChild(sp_cloud1);
    
    CCSprite *sp_cloud2=CCSprite::createWithSpriteFrameName("cloud2.png");//cloud2
    sp_cloud2->setPosition(ccpAdd(point, ccp(150, 300)));
    addChild(sp_cloud2);
    
    CCRepeatForever *repeate_cloud1=CCRepeatForever::create(CCMoveBy::create(0.2, ccp(9, 0)));
    sp_cloud1->runAction(repeate_cloud1);
    
    CCRepeatForever *repeate_cloud2=CCRepeatForever::create(CCMoveBy::create(0.2, ccp(5, 0)));
    sp_cloud2->runAction(repeate_cloud2);
    
    CCSprite *sp_leaf1=CCSprite::createWithSpriteFrameName("leaf-1.png");//leaf-1
    sp_leaf1->setPosition(ccpAdd(point, ccp(230, 280)));
     addChild(sp_leaf1);
    
    CCSprite *sp_leaf3=CCSprite::createWithSpriteFrameName("leaf-3.png");//leaf-3
    sp_leaf3->setPosition(ccpAdd(point, ccp(400, 280)));
    addChild(sp_leaf3);
    
    CCSprite *sp_leaf2=CCSprite::createWithSpriteFrameName("leaf-2.png");//leaf-2
    sp_leaf2->setAnchorPoint(ccp(0.5, 0));
    sp_leaf2->setPosition(ccpAdd(point, ccp(300, 210)));
    addChild(sp_leaf2);
    
    CCRotateBy *rotateBy=CCRotateBy::create(0.05, 20);
    CCDelayTime *leaf2_delay=CCDelayTime::create(2);
    CCSequence *leaf2_sequence=CCSequence::create(rotateBy,rotateBy->reverse(),leaf2_delay,NULL);
    CCRepeatForever *repeate_leaf2=CCRepeatForever::create(leaf2_sequence);
    sp_leaf2->runAction(repeate_leaf2);
    
    CCSprite *sp_carrot=CCSprite::createWithSpriteFrameName("carrot.png");//carrot
    sp_carrot->setPosition(ccpAdd(point, ccp(325, 150)));
    addChild(sp_carrot);
    
    CCSprite *sp_mainBg=CCSprite::createWithSpriteFrameName("mainbg_CN.png");//mainbg_cn
    sp_mainBg->setPosition(this->getAnchorPointInPoints());
    addChild(sp_mainBg);
    //按钮层
    CCControlButton *settingBtn=createButton("btn_setting_normal.png","btn_setting_pressed.png");//setting
    settingBtn->setPosition(ccp(150, 200));
    addChild(settingBtn);
    
    CCControlButton *helpBtn=createButton("btn_help_normal.png","btn_help_pressed.png");//help
    helpBtn->setPosition(ccp(710, 200));
      addChild(helpBtn);
    
    CCControlButton *adventureBtn=createButton("btn_adventure_normal_CN.png","btn_adventure_pressed_CN.png");//adventure
    adventureBtn->setPosition(ccp(150, 100));
     addChild(adventureBtn);
    
    CCControlButton *bossBtn=createButton("btn_boss_normal_CN.png","btn_boss_pressed_CN.png");//boss
    bossBtn->setPosition(ccpAdd(adventureBtn->getPosition(), ccp(adventureBtn->getContentSize().width+50, 0)));
      addChild(bossBtn);
    
    CCControlButton *nestBtn=createButton("btn_nest_normal_CN.png","btn_nest_pressed_CN.png");//nest
    nestBtn->setPosition(point);
    nestBtn->setPosition(ccpAdd(bossBtn->getPosition(),ccp(bossBtn->getContentSize().width+50, 0)));
     addChild(nestBtn);

    CCSprite *sp_lock=CCSprite::createWithSpriteFrameName("locked.png");//lock
    sp_lock->setPosition(point);
    addChild(sp_lock);
    
    CCSprite *sp_btnBg=CCSprite::createWithSpriteFrameName("btn_bg.png");//右上角的雷达背景
    sp_btnBg->setAnchorPoint(ccp(1, 1));
    sp_btnBg->setPosition(ccp(winSize.width, winSize.height));
    addChild(sp_btnBg);
    
    CCControlButton *btn18183=createButton("18183_normal.png","18183_press.png");//18183
    //    btn18183->setPreferredSize(CCSizeMake(68,60));
    btn18183->setPosition(point);
    //    addChild(btn18183);
    
    CCControlButton *closeBtn=createButton("code_close_normal.png","code_close_pressed.png");//close
    closeBtn->setPosition(point);
    //  addChild(closeBtn);
    
    CCControlButton *newsBtn=createButton("news_normal.png","news_pressed.png");//news
    newsBtn->setPosition(point);
    addChild(newsBtn);
    
    CCSprite *sp_logo91=CCSprite::createWithSpriteFrameName("91-logo.png");
    sp_logo91->setPosition(ccpAdd(point, ccp(150, 150)));
    // addChild(sp_logo91);
    
    CCSprite *sp_free=CCSprite::createWithSpriteFrameName("btn_freestone.png");//免费的宝石
    sp_free->setPosition(ccpAdd(point, ccp(150, 150)));
   // addChild(sp_free);
    
    CCSprite *sp_codeBg=CCSprite::createWithSpriteFrameName("code_bg.png");//宝石兑换背景
    sp_codeBg->setPosition(ccpAdd(point, ccp(150, 150)));
   // addChild(sp_codeBg);
    
    return true;
}

CCControlButton * MainLayer::createButton(const char *normal,const char *pressed){
    CCScale9Sprite* pressSprite= CCScale9Sprite::createWithSpriteFrameName(pressed);
    CCControlButton *button=CCControlButton::create(CCScale9Sprite::createWithSpriteFrameName(normal));
    button->setBackgroundSpriteForState(pressSprite, CCControlStateHighlighted);
    button->setPreferredSize(CCSizeMake(pressSprite->getContentSize().width, pressSprite->getContentSize().height));
    return button;
}
//    "btn_adventure_normal_EN.png "
//    "btn_adventure_normal_EN.png "
//    "btn_adventure_normal_TW.png "
//    "btn_adventure_pressed_EN.png "
//    "btn_adventure_pressed_TW.png "
////    "btn_boss_normal_EN.png "
//    "btn_boss_normal_TW.png "
//    "btn_boss_pressed_EN.png "
//    "btn_boss_pressed_TW.png "
//    "btn_nest_normal_EN.png "
//    "btn_nest_normal_TW.png "
//    "btn_nest_pressed_EN.png "
//    "mainbg_CN.png "//
//    "mainbg_EN.png "//
//    "mainbg_TW.png "
//    "weiboicon01_normal.png "
//    "weiboicon01_press.png "
//    "weiboicon02_normal.png "
//    "weiboicon02_press.png "
//    "weiboicon03_normal.png "
//    "weiboicon03_press.png "
//    "weiboicon04_normal.png "
//    "weiboicon04_press.png "
//    "weiboicon05_normal.png "
//    "weiboicon05_press.png "
//    "weiboicon06_normal.png "
//    "weiboicon06_press.png "