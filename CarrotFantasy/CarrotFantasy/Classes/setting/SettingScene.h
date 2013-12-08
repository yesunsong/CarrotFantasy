//
//  SettingScene.h
//  CarrotFantasy
//
//  Created by 叶孙松 on 13-12-8.
//
//

#ifndef __CarrotFantasy__SettingScene__
#define __CarrotFantasy__SettingScene__

#include "cocos2d.h"
#include "cocos-ext.h"
USING_NS_CC;
USING_NS_CC_EXT;

class SettingScene : public cocos2d::CCScene{
public:
    virtual bool init();
    CREATE_FUNC(SettingScene);    
    CCSize winSize;
};

#endif /* defined(__CarrotFantasy__SettingScene__) */
