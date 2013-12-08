//
//  Command.h
//  CarrotFantasy
//
//  Created by 叶孙松 on 13-12-8.
//
//

#ifndef __CarrotFantasy__Command__
#define __CarrotFantasy__Command__

#include "cocos2d.h"
#include "Core.h"
using namespace std;
USING_NS_CC;

class Notification;
class Command:public CCObject{
public:
    Command();
    virtual ~Command();
    virtual bool init();
    CREATE_FUNC(Command);
    
    static const char *NAME(){
    return "command";
    }
    
    virtual void execute(Notification *notification);
    const char *getCommandName();
private:
    const char * _command_name;
};

#endif /* defined(__CarrotFantasy__Command__) */
