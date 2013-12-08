//
//  MainLayer.h
//  CarrotFantasy
//
//  Created by 叶孙松 on 13-12-8.
//
//

#ifndef __CarrotFantasy__MainLayer__
#define __CarrotFantasy__MainLayer__

#include "cocos2d.h"
#include "cocos-ext.h"
USING_NS_CC;
USING_NS_CC_EXT;

class MainLayer : public cocos2d::CCLayer{
public:
    virtual bool init();
    CREATE_FUNC(MainLayer);
    CCControlButton * createButton(const char *normal,const char *pressed);
    
    CCSize winSize;
};

#endif /* defined(__CarrotFantasy__MainLayer__) */
