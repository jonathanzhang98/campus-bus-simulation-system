
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

        picojson::object cStruct;
        cStruct["red"] = picojson::value(static_cast<double>(busses[i].color.red));
        cStruct["green"] = picojson::value(static_cast<double>(busses[i].color.green));
        cStruct["blue"] = picojson::value(static_cast<double>(busses[i].color.blue));
        cStruct["alpha"] = picojson::value(static_cast<double>(busses[i].color.alpha));
        s["color"] = picojson::value(cStruct);

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

PauseCommand::PauseCommand(VisualizationSimulator* sim): mySim(sim) {}

void PauseCommand::execute(MyWebServerSession* session, picojson::value& command, MyWebServerSessionState* state) {
    // TODO: Call Pause() on the associated VisualizationSimulator
    (void)session;
    (void)state;
    (void)command;
    
    mySim->Pause();
}

class BusWebObserver : public IObserver <BusData>{
public:
    BusWebObserver(MyWebServerSession* session) : session(session) {}

    void UpdateObserver(BusData* info) { // This normally called update, but we call it Notify as per the lab writeup
        picojson::object data;
        data["command"] = picojson::value("observeBus");
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

class StopWebObserver : public IObserver <StopData>{
public:
    StopWebObserver(MyWebServerSession* session) : session(session) {}

    void UpdateObserver(StopData* info) { // This normally called update, but we call it Notify as per the lab writeup
        picojson::object data;
        data["command"] = picojson::value("observeStop");
        std::stringstream ss;
        ss << "Stop " << info->id << "\n";
        ss << "-----------------------------\n";
        ss << "  * Position: (" << info->position.x << "," << info->position.y << ")\n";
        ss << "  * People: " << info->num_people << "\n";
        std::cout << "StopWebObserver Got call!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";

        data["text"] = picojson::value(ss.str());
        picojson::value ret(data);
        session->sendJSON(ret);
    }
private:
    MyWebServerSession* session;
};


AddBusListenerCommand::AddBusListenerCommand(VisualizationSimulator* sim) : mySim(sim) {}

void AddBusListenerCommand::execute(MyWebServerSession* session, picojson::value& command, MyWebServerSessionState* state) {
    mySim->ClearBusListeners();
    std::cout << "starting AddBusListenerCommand::execute" << std::endl;
    std::string id = command.get<picojson::object>()["id"].get<std::string>();
    std::cout << id << std::endl;
    mySim->AddBusListener(&id, new BusWebObserver(session));
}

AddStopListenerCommand::AddStopListenerCommand(VisualizationSimulator* sim) : mySim(sim) {}

void AddStopListenerCommand::execute(MyWebServerSession* session, picojson::value& command, MyWebServerSessionState* state) {
    mySim->ClearStopListeners();
    std::cout << "starting AddStopListenerCommand::execute" << std::endl;
    std::string id = command.get<picojson::object>()["id"].get<std::string>();
    std::cout << id << std::endl;
    mySim->AddStopListener(&id, new StopWebObserver(session));
}