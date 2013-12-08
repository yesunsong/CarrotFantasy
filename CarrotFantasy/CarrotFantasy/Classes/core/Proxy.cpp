//
//  Proxy.cpp
//  CarrotFantasy
//
//  Created by 叶孙松 on 13-12-8.
//
//

#include "Proxy.h"

Proxy::Proxy(){}
Proxy::~Proxy(){}
bool Proxy::initProxy(const char *name){
    _proxy_name=new char[strlen(name)+1];
    strcpy(_proxy_name, name);
    return true;
}

char *Proxy::getProxyName()const{
    return _proxy_name;
}

void Proxy::postNotificaionName(const char *notificationName, cocos2d::CCObject *object){
    string name="";
    name.append(_proxy_name);
    name.append("_");
    name.append(notificationName);
    Core::shareCore()->postNotification(name.c_str(), object);
    name.clear();
}

void Proxy::update(){

}