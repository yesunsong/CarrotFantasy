//
//  Command.cpp
//  CarrotFantasy
//
//  Created by 叶孙松 on 13-12-8.
//
//

#include "Command.h"

Command::Command(){
}
Command::~Command(){
}
bool Command::init(){
    return true;
}

const char *Command::getCommandName(){
    return _command_name;
}

void Command::execute(Notification *notification){

}