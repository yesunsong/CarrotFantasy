//
//  View.h
//  CarrotFantasy
//
//  Created by 叶孙松 on 13-12-8.
//
//

#ifndef __CarrotFantasy__View__
#define __CarrotFantasy__View__

#define CREATE_VIEW(__TYPE__) \
static __TYPE__* createView(const char *name,CCObject *component){ \
__TYPE__ *pRect=new __TYPE__(); \
if(pRect && pRect->initView(name,component)){ \
pRect->autorelease(); \
return pRect; \
}else{ \
delete pRect; \
pRect=NULL; \
return NULL; \
} \
} \

#include "cocos2d.h"
#include "Core.h"
#include <iostream>
using namespace std;
USING_NS_CC;

class View:public CCObject{
public:
    View();
    virtual ~View();
    virtual bool initView(const char *name,CCObject *component);
    CREATE_VIEW(View);
    
    static const char *NAME(){
        return "View";
    }
    const char *getViewName();
    
    void addObserver(const char * proxyDefaultName,const char *notificationName,SEL_CallFuncO selector);
    void removeObserver(const char * proxyDefaultName,const char *notificationName);
    void postNotification(const char *name, cocos2d::CCObject *object);
private:
    char * _viewName;
    CCObject *_component;
};


#endif /* defined(__CarrotFantasy__View__) */
