#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

#include "MainLayer.h"

#include "SettingScene.h"

using namespace cocos2d;
using namespace CocosDenshion;

CCScene* HelloWorld::scene(){
    CCScene *scene = CCScene::create();
    HelloWorld *layer = HelloWorld::create();
    scene->addChild(layer);
    return scene;
}

bool HelloWorld::init(){
    if ( !CCLayer::init() )    {
        return false;
    }
    CCPoint point=ccp(150,150);
    
//    addChild(SettingLayer::create());
    SettingScene *scen=SettingScene::create();
    addChild(scen);
	
    
    return true;
}

CCControlButton * HelloWorld::createButton(const char *normal,const char *pressed){
    CCScale9Sprite* pressSprite= CCScale9Sprite::createWithSpriteFrameName(pressed);
    CCControlButton *button=CCControlButton::create(CCScale9Sprite::createWithSpriteFrameName(normal));
    button->setBackgroundSpriteForState(pressSprite, CCControlStateHighlighted);
    button->setPreferredSize(CCSizeMake(pressSprite->getContentSize().width, pressSprite->getContentSize().height));
    return button;
}

void HelloWorld::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
