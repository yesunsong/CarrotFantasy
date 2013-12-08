//
//  SettingLayer.h
//  CarrotFantasy
//
//  Created by 叶孙松 on 13-12-8.
//
//

#ifndef __CarrotFantasy__SettingLayer__
#define __CarrotFantasy__SettingLayer__

#include "cocos2d.h"
#include "cocos-ext.h"
USING_NS_CC;
USING_NS_CC_EXT;

class SettingLayer : public cocos2d::CCLayer{
public:
    virtual bool init();
    CREATE_FUNC(SettingLayer);
    CCControlButton * createButton(const char *normal,const char *pressed);
    
    CCSize winSize;
};

#endif /* defined(__CarrotFantasy__SettingLayer__) */
