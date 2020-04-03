
#ifndef MY_WEB_SERVER_COMMAND_H
#define MY_WEB_SERVER_COMMAND_H

#include "config_manager.h"
#include "visualization_simulator.h"

#include "my_web_server_session.h"
#include "my_web_server_session_state.h"
#include "my_web_server.h"
#include "data_structs.h"

#include <vector>

class MyWebServerSession;
class MyWebServerSessionState;

class MyWebServerCommand {
public:
	virtual ~MyWebServerCommand() {}
	virtual void execute(MyWebServerSession* session, picojson::value& command, MyWebServerSessionState* state) = 0;
};


///***** * * * * * COMMANDS * * * * * ******///

class GetRoutesCommand : public MyWebServerCommand {
    public:
	    GetRoutesCommand(MyWebServer* ws);
        void execute(MyWebServerSession* session, picojson::value& command, MyWebServerSessionState* state) override;
    private:
        MyWebServer* myWS;
};

class GetBussesCommand : public MyWebServerCommand {
    public:
	    GetBussesCommand(MyWebServer* ws);
	    void execute(MyWebServerSession* session, picojson::value& command, MyWebServerSessionState* state) override;
    private:
        MyWebServer* myWS;
};

class StartCommand : public MyWebServerCommand {
    public:
        StartCommand(VisualizationSimulator* sim);
        void execute(MyWebServerSession* session, picojson::value& command, MyWebServerSessionState* state) override;
    private:
        VisualizationSimulator* mySim;
        std::vector<int> timeBetweenBusses;
        int numTimeSteps;
};

class UpdateCommand : public MyWebServerCommand {
    public:
        UpdateCommand(VisualizationSimulator* sim);
        void execute(MyWebServerSession* session, picojson::value& command, MyWebServerSessionState* state) override;
    private:
        VisualizationSimulator* mySim;
};

class PauseCommand : public MyWebServerCommand {
    public:
        PauseCommand(VisualizationSimulator* sim);
        void execute(MyWebServerSession* session, picojson::value& command, MyWebServerSessionState* state) override;
    private:
        VisualizationSimulator* mySim;

};

class AddListenerCommand: public MyWebServerCommand {
    public:
        AddListenerCommand(VisualizationSimulator* sim);
        void execute(MyWebServerSession* session, picojson::value& command, MyWebServerSessionState* state) override;
    private:
        VisualizationSimulator* mySim;
};

class InitRoutesCommand : public MyWebServerCommand {
    public:
        InitRoutesCommand(ConfigManager* cm);
        void execute(MyWebServerSession* session, picojson::value& command, MyWebServerSessionState* state) override;
    private:
        ConfigManager* cm;
};



#endif // MY_WEB_SERVER_COMMAND_H
