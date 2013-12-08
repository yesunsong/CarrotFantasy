//
//  View.cpp
//  CarrotFantasy
//
//  Created by 叶孙松 on 13-12-8.
//
//

#include "View.h"

const char *View::getViewName(){
    return _viewName;
}

View::View():
_viewName(NULL)
,_component(NULL)
{
}
 View::~View(){
 }

 bool View::initView(const char *name, cocos2d::CCObject *component){
     _viewName=new char[strlen(name)+1];
     strcpy(_viewName, name);
     _component=component;
     _component->retain();
     return true;
 }

void View::addObserver(const char * proxyDefaultName,const char *notificationName,SEL_CallFuncO selector){
    string name="";
    name.append(proxyDefaultName);
    name.append("_");
    name.append(notificationName);
    Core::shareCore()->addObserver(this, selector, name.c_str(), NULL);
    name.clear();
}

void View::removeObserver(const char * proxyDefaultName,const char *notificationName){
    string name="";
    name.append(proxyDefaultName);
    name.append("_");
    name.append(notificationName);
    Core::shareCore()->removeObserver(this, name.c_str());
    name.clear();
}