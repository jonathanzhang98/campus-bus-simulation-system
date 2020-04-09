
#include "my_web_server_command.h" 
#include <sstream>


GetRoutesCommand::GetRoutesCommand(MyWebServer* ws) : myWS(ws) {}
void GetRoutesCommand::execute(MyWebServerSession* session, picojson::value& command, MyWebServerSessionState* state) {
    // Unsused input
    (void)command;
    (void)state;
    
    std::vector<RouteData> routes = myWS->routes;

    //std::cout << "Updating routes" << std::endl;

    picojson::object data;
    data["command"] = picojson::value("updateRoutes");

    picojson::array routesArray;

    for (int i = 0; i < static_cast<int>(routes.size()); i++) {
        picojson::object r;
        r["id"] = picojson::value(routes[i].id);

        picojson::array stopArray;
        for (int j = 0; j < static_cast<int>(routes[i].stops.size()); j++) {
            picojson::object stopStruct;
            stopStruct["id"] = picojson::value(routes[i].stops[j].id);
            stopStruct["numPeople"] = picojson::value(static_cast<double>(routes[i].stops[j].num_people));

            picojson::object pStruct;
            pStruct["x"] = picojson::value(routes[i].stops[j].position.x);
            pStruct["y"] = picojson::value(routes[i].stops[j].position.y);
            
            stopStruct["position"] = picojson::value(pStruct);

            stopArray.push_back(picojson::value(stopStruct));
        }

        r["stops"] = picojson::value(stopArray);
        routesArray.push_back(picojson::value(r));
    }
    data["routes"] = picojson::value(routesArray);

    picojson::value ret(data);

    session->sendJSON(ret);
}



GetBussesCommand::GetBussesCommand(MyWebServer* ws) : myWS(ws) {}
void GetBussesCommand::execute(MyWebServerSession* session, picojson::value& command, MyWebServerSessionState* state) {
    // Unsused input
    (void)command;
    (void)state;
    
    std::vector<BusData> busses = myWS->busses;
    
    //std::cout << "Updating Busses" << std::endl;

    picojson::object data;
    data["command"] = picojson::value("updateBusses");
   
    picojson::array bussesArray;

    for (int i = 0; i < static_cast<int>(busses.size()); i++) {
        picojson::object s;
        s["id"] = picojson::value(busses[i].id);
        s["numPassengers"] = picojson::value(static_cast<double>(busses[i].num_passengers));
        s["capacity"] = picojson::value(static_cast<double>(busses[i].capacity));
        
        picojson::object pStruct;
        pStruct["x"] = picojson::value(busses[i].position.x);
        pStruct["y"] = picojson::value(busses[i].position.y);

        s["position"] = picojson::value(pStruct);

        bussesArray.push_back(picojson::value(s));
    }

    data["busses"] = picojson::value(bussesArray);

    picojson::value ret(data);

    session->sendJSON(ret);
}



StartCommand::StartCommand(VisualizationSimulator* sim) : mySim(sim), timeBetweenBusses(std::vector<int>()), numTimeSteps(10) {

}
void StartCommand::execute(MyWebServerSession* session, picojson::value& command, MyWebServerSessionState* state) {
    // Unused variables
    (void)session;
    (void)state;

    timeBetweenBusses.clear();

    numTimeSteps = static_cast<float>(command.get<picojson::object>()["numTimeSteps"].get<double>());
    
    picojson::array arr = command.get<picojson::object>()["timeBetweenBusses"].get<picojson::array>();
    for (picojson::array::iterator it = arr.begin(); it != arr.end(); it++) {
        timeBetweenBusses.push_back(static_cast<int>(it->get<double>()));
    }

    for (int i = 0; i < static_cast<int>(timeBetweenBusses.size()); i++) {
        std::cout << "Time between busses for route  " << i <<  ": " << timeBetweenBusses[i] << std::endl;
    }
    
    std::cout << "Number of time steps for simulation is: " << numTimeSteps << std::endl;
    std::cout << "Starting simulation" << std::endl;

    mySim->Start(timeBetweenBusses, numTimeSteps);
}




UpdateCommand::UpdateCommand(VisualizationSimulator* sim): mySim(sim) {}

void UpdateCommand::execute(MyWebServerSession* session, picojson::value& command, MyWebServerSessionState* state) {
    (void)session;
    (void)state;
    (void)command;

    mySim->Update();
}


PauseCommand::PauseCommand(VisualizationSimulator* sim) : mySim(sim) {}

void PauseCommand::execute(MyWebServerSession* session, picojson::value& command, MyWebServerSessionState* state) {
    mySim->TogglePause();
}


class BusWebObserver : public IObserver {
public:
    BusWebObserver(MyWebServerSession* session) : session(session) {}

    void Notify(BusData* info) { // This normally called update, but we call it Notify as per the lab writeup
        picojson::object data;
        data["command"] = picojson::value("observe");
        std::stringstream ss;
        ss << "Bus " << info->id << "\n";
        ss << "-----------------------------\n";
        ss << "  * Position: (" << info->position.x << "," << info->position.y << ")\n";
        ss << "  * Passengers: " << info->num_passengers << "\n";
        ss << "  * Capacity: " << info->capacity << "\n";
        data["text"] = picojson::value(ss.str());
        picojson::value ret(data);
        session->sendJSON(ret);
    }
private:
    MyWebServerSession* session;
};

AddListenerCommand::AddListenerCommand(VisualizationSimulator* sim) : mySim(sim) {}

void AddListenerCommand::execute(MyWebServerSession* session, picojson::value& command, MyWebServerSessionState* state) {
    mySim->ClearListeners();
    std::cout << "starting AddListenerCommand::execute" << std::endl;
    std::string id = command.get<picojson::object>()["id"].get<std::string>();
    std::cout << id << std::endl;
    mySim->AddListener(&id, new BusWebObserver(session));
}

InitRoutesCommand::InitRoutesCommand(ConfigManager* configManager) : cm(configManager) {}

void InitRoutesCommand::execute(MyWebServerSession* session, picojson::value& command, MyWebServerSessionState* state) {
    (void)state;
    (void)command;

    int  numRoutes = static_cast<int>(cm->GetRoutes().size());

    picojson::object data;
    data["command"] = picojson::value("initRoutes");
    data["numRoutes"] = picojson::value(static_cast<double>(numRoutes));
    
    picojson::value ret(data);
    session->sendJSON(ret);

}

