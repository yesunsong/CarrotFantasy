//
//  Proxy.h
//  CarrotFantasy
//
//  Created by 叶孙松 on 13-12-8.
//
//

#ifndef __CarrotFantasy__Proxy__
#define __CarrotFantasy__Proxy__

#define CREATE_PROXY(__TYPE__) \
static __TYPE__* createView(const char *name){ \
__TYPE__ *pRect=new __TYPE__(); \
if(pRect && pRect->initProxy(name)){ \
pRect->autorelease(); \
return pRect; \
}else{ \
delete pRect; \
pRect=NULL; \
return NULL; \
} \
} \

#include "cocos2d.h"
#include <string>
#include "Core.h"
using namespace std;
USING_NS_CC;

class Proxy:public CCObject{
public:
    Proxy();
    virtual ~Proxy();
    virtual bool initProxy(const char *name);
    CREATE_PROXY(Proxy);
    static const char *NAME(){
    return "proxy";
    }
    
   virtual char *getProxyName()const;//???
    virtual void update();
    
private:
    char * _proxy_name;
    void postNotificaionName(const char *name,CCObject *object);
};

#endif /* defined(__CarrotFantasy__Proxy__) */
