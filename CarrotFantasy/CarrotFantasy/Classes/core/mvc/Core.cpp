//
//  Core.cpp
//  CarrotFantasy
//
//  Created by 叶孙松 on 13-12-8.
//
//

#include "Core.h"

static Core* pCore=NULL;

Core::Core():
pViews(NULL),
pModels(NULL),
pProxys(NULL),
pCommands(NULL){
}

Core::~Core(){
    do { if(pViews) { (pViews)->release(); (pViews) = 0; } } while(0);
    do { if(pCommands) { (pCommands)->release(); (pCommands) = 0; } } while(0);
    do { if(pProxys) { (pProxys)->release(); (pProxys) = 0; } } while(0);
    CCNotificationCenter::purgeNotificationCenter();
}

Core* Core::shareCore(){
    if (pCore==NULL) {
        pCore=Core::create();
        pCore->autorelease();
    }
    return pCore;
}

void Core::purgeCore(void){
    do { if(pCore) { (pCore)->release(); (pCore) = 0; } } while(0);
}

bool Core::init(){
    pViews=CCDictionary::create();
    pViews->retain();
    
    pModels=CCDictionary::create();
    pModels->retain();
    
    pProxys=CCDictionary::create();
    pProxys->retain();
    
    pCommands=CCDictionary::create();
    pCommands->retain();
    
    return true;
}
//***************************************************************
void Core::addView(View *view){
    View *tmp_view=(View *)pViews->objectForKey(view->getViewName());
    if (tmp_view==NULL) {
        pViews->setObject(view, view->getViewName());
    }else{
        CCLog("View occured:--%s",view->getViewName());
    }
}

void Core::removeView(const char *name){
    View *tmp_view=(View *)pViews->objectForKey(name);
    if (tmp_view!=NULL) {
        pViews->removeObjectForKey(name);
    }else{
        CCLog("Not existed view:--%s",name);
    }
}

View* Core::getView(const char *name){
    View *tmp_view=(View *)pViews->objectForKey(name);
    if (tmp_view!=NULL) {
        return tmp_view;
    }
    return NULL;
}
//***************************************************************
void Core::addModel(Model *model){
}
void Core::removeModel(const char *name){
}
Model* Core::getModel(const char *name){
    
}
//***************************************************************
void Core::addProxy(Proxy * proxy){
    if (pProxys->objectForKey(proxy->getProxyName())==NULL) {
//        proxy->onAdd();
        pProxys->setObject(proxy, proxy->getProxyName());
    }else{
        CCLOG("Proxy [%s ] 已经存在！",proxy->getProxyName());
    }
}

void Core::removeProxy(const char* name){
    Proxy * proxy=(Proxy *)pProxys->objectForKey(name);
    if (proxy!=NULL) {
//        proxy->onRemove();
        pProxys->removeObjectForKey(name);
    }
}

Proxy * Core::getProxy(const char* name){
    return (Proxy *)pProxys->objectForKey(name);
}
//***************************************************************
void Core::addCommand(const char *notificationName,Command *command){
    if (pCommands->objectForKey(notificationName)==NULL) {
        pCommands->setObject(command,notificationName);
        this->addObserver(this, callfuncO_selector(Core::executeCommand), notificationName, NULL);
    }else{
        CCLog("Command existed:--%s",notificationName);
    }
}
void Core::removeCommand(const char *notificationName){
    Command *command=(Command*)pCommands->objectForKey(notificationName);
    if (command) {
        pCommands->removeObjectForKey(notificationName);
        this->removeObserver(this, notificationName);
    }else{
        CCLog("Not existed Command:--%s",notificationName);
    }
    
}
void Core::executeCommand(Notification *notification){

}
//***************************************************************
void Core::addObserver(cocos2d::CCObject *target, SEL_CallFuncO selector, const char *name, cocos2d::CCObject *obj){
    CCNotificationCenter::sharedNotificationCenter()->addObserver(target, selector, name, obj);
}
void Core::removeObserver(cocos2d::CCObject *target, const char *name){
    CCNotificationCenter::sharedNotificationCenter()->removeObserver(target, name);
}
void Core::postNotification(const char *name, cocos2d::CCObject *object){
    Notification * notification=new Notification(name,object);
    if(notification){
        notification->autorelease();
        CCNotificationCenter::sharedNotificationCenter()->postNotification(name, notification);
    }
//    CCNotificationCenter::sharedNotificationCenter()->postNotification(name,object);
}
//***************************************************************
//***************************************************************
Notification::Notification(const char *name,CCObject *object){
    _name=new char[strlen(name)+1];
    memset(_name, 0, strlen(name)+1);
    strcpy(_name, name);
    _object=object;
}

Notification::~Notification(){
    do {if (_name) {delete [] _name; _name=0;}} while (0);
}

char * Notification::getName(){
    return _name;
}

CCObject * Notification::getObject(){
    return _object;
}

void Notification::setObject(CCObject *object){
    _object=object;
}

