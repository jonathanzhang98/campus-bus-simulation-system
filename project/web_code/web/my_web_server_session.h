
#ifndef MY_WEB_SERVER_SESSION_H
#define MY_WEB_SERVER_SESSION_H

#include "WebServer.h"
#include "my_web_server_session_state.h"


class MyWebServerSession : public JSONSession {
    public:
        MyWebServerSession(MyWebServerSessionState s) : state(s) {}
        ~MyWebServerSession() {}

        void receiveJSON(picojson::value& val) override;
        void update() override {}

    private:
        MyWebServerSessionState state;
};


#endif // MY_WEB_SERVER_SESSION_H
