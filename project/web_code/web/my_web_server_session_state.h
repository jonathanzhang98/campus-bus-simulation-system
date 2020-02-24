
#ifndef MY_WEB_SERVER_SESSION_STATE_H
#define MY_WEB_SERVER_SESSION_STATE_H

#include <string>
#include <map>

class MyWebServerCommand;

struct MyWebServerSessionState {
    MyWebServerSessionState() : commands(std::map<std::string, MyWebServerCommand*>()) {}
    std::map<std::string, MyWebServerCommand*> commands;
};

#endif // MY_WEB_SERVER_SESSION_STATE_H
