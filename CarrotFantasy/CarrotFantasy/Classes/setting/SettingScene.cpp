//
//  SettingScene.cpp
//  CarrotFantasy
//
//  Created by 叶孙松 on 13-12-8.
//
//

#include "SettingScene.h"
#include "SettingLayer.h"
#include "ButtonLayer.h"
#include "CreditsLayer.h"
#include "StaticsLayer.h"

bool SettingScene::init(){
    if (!CCScene::init()) {
        return false;
    }
    SettingLayer *setting=SettingLayer::create();
    ButtonLayer *button=ButtonLayer::create();
    CreditsLayer *credits=CreditsLayer::create();
    StaticsLayer *statics=StaticsLayer::create();
    
    CCLayerMultiplex *multiLayers=CCLayerMultiplex::create(setting,statics,credits,NULL);
    addChild(multiLayers);
    addChild(button);
    return true;
}