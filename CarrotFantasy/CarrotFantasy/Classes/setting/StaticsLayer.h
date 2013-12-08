//
//  StaticsLayer.h
//  CarrotFantasy
//
//  Created by 叶孙松 on 13-12-8.
//
//

#ifndef __CarrotFantasy__StaticsLayer__
#define __CarrotFantasy__StaticsLayer__

#include "cocos2d.h"
#include "cocos-ext.h"
USING_NS_CC;
USING_NS_CC_EXT;

class StaticsLayer : public cocos2d::CCLayer{
public:
    virtual bool init();
    CREATE_FUNC(StaticsLayer);
    CCControlButton * createButton(const char *normal,const char *pressed);
    
    CCSize winSize;
};

#endif /* defined(__CarrotFantasy__StaticsLayer__) */
