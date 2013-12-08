//
//  Core.h
//  CarrotFantasy
//
//  Created by 叶孙松 on 13-12-8.
//
//

#ifndef __CarrotFantasy__Core__
#define __CarrotFantasy__Core__

#include "cocos2d.h"
#include "View.h"
#include "Model.h"
#include "Proxy.h"
#include "Command.h"
using namespace std;

class View;
class Proxy;
class Command;
class Notification;

//NS_CC_BEGIN

class Core:public CCObject{
public:
    Core();
    virtual ~Core();
    virtual bool init();
    CREATE_FUNC(Core);
    //***************************************************************
    void addView(View *view);
    void removeView(const char *name);
    View* getView(const char *name);
    //***************************************************************
    void addModel(Model *model);
    void removeModel(const char *name);
    Model* getModel(const char *name);
    //***************************************************************
    void addProxy(Proxy * proxy);
    void removeProxy(const char* name);
    Proxy *getProxy(const char* name);
    //***************************************************************
    void addCommand(const char *notificationName,Command *command);
    void removeCommand(const char *notificationName);
    void executeCommand(Notification *notification);
    //***************************************************************
    void addObserver(cocos2d::CCObject *target, SEL_CallFuncO selector, const char *name, cocos2d::CCObject *obj);
    void removeObserver(cocos2d::CCObject *target, const char *name);
    void postNotification(const char *name, cocos2d::CCObject *object);
    //***************************************************************
    static Core *shareCore();
    static void purgeCore(void);
private:    
    CCDictionary *pViews;
    CCDictionary *pModels;
    CCDictionary *pProxys;
    CCDictionary *pCommands;
};


class Notification:public CCObject{
public:
    Notification(const char *name,CCObject *object);
    ~Notification();
    
    char *getName();
    CCObject *getObject();
    void setObject(CCObject *object);
private:
     char *_name;
     CCObject *_object;
};
//NS_CC_END

#endif /* defined(__CarrotFantasy__Core__) */
