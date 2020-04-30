
#include "visualization_simulator.h"

#include "bus.h"
#include "route.h"
#include <iostream>
#include <sstream>
#include <fstream>

VisualizationSimulator::VisualizationSimulator(WebInterface* webI, ConfigManager* configM) {
    webInterface_ = webI;
    configManager_ = configM;
}

VisualizationSimulator::~VisualizationSimulator() {

}

void VisualizationSimulator::Start(const std::vector<int>& busStartTimings, const int& numTimeSteps) {
    busStartTimings_ = busStartTimings;
    numTimeSteps_ = numTimeSteps;
    started = true;
    paused = false;

    timeSinceLastBus_.resize(busStartTimings_.size());
    for (int i = 0; i < static_cast<int>(timeSinceLastBus_.size()); i++) {
        timeSinceLastBus_[i] = 0;
    }

    simulationTimeElapsed_ = 0;

    prototypeRoutes_ = configManager_->GetRoutes();
    for (int i = 0; i < static_cast<int>(prototypeRoutes_.size()); i++) {
        prototypeRoutes_[i]->Report(std::cout);
        
        prototypeRoutes_[i]->UpdateRouteData();
        webInterface_->UpdateRoute(prototypeRoutes_[i]->GetRouteData());
    }

}

void VisualizationSimulator::Update() {
    if (paused || !started) {
        return;
    }

    simulationTimeElapsed_++;

    std::cout << "~~~~~~~~~~ The time is now " << simulationTimeElapsed_;
    std::cout << "~~~~~~~~~~" << std::endl;

    std::cout << "~~~~~~~~~~ Generating new busses if needed ";
    std::cout << "~~~~~~~~~~" << std::endl;

    // Check if we need to generate new busses
    for (int i = 0; i < static_cast<int>(timeSinceLastBus_.size()); i++) {
        // Check if we need to make a new bus
        if (0 >= timeSinceLastBus_[i]) {

            Route * outbound = prototypeRoutes_[2 * i];
            Route * inbound = prototypeRoutes_[2 * i + 1];
            
            // std::random_device dev;
            // std::mt19937 rng(dev());
            // std::uniform_int_distribution<std::mt19937::result_type> dist1(1, 3);
            // int rand_int = dist1(rng);
            // std::cout << "Random generated: -------------------------------------" << rand_int << std::endl;
            // old code: busses_.push_back(new Bus(std::to_string(busId), outbound->Clone(), inbound->Clone(), 60, 1));
            // busses_.push_back(ConcreteBusFactory::GenerateBus(std::to_string(busId), outbound->Clone(), inbound->Clone(), rand_int, 1));

            IBus * new_bus = new BusColorDecorator(ConcreteBusFactory::GenerateBus(std::to_string(busId), outbound->Clone(), inbound->Clone(), 1));
            // busses_.push_back(ConcreteBusFactory::GenerateBus(std::to_string(busId), outbound->Clone(), inbound->Clone(), 1));
            busses_.push_back(new_bus);
            busId++;
            
            timeSinceLastBus_[i] = busStartTimings_[i];
        } else {
            timeSinceLastBus_[i]--;
        }
    }   
    
    std::cout << "~~~~~~~~~ Updating busses ";
    std::cout << "~~~~~~~~~" << std::endl;

    // Update busses
    for (int i = static_cast<int>(busses_.size()) - 1; i >= 0; i--) {
        busses_[i]->Update();

        if (busses_[i]->IsTripComplete()) { 
            std::ostringstream outStr;
            outStr << "Name," << busses_[i]->GetName() << ","
            << "Total,Num,of,Passengers," << busses_[i]->GetTotalPassengers();
            FileWriter::GetInstance()->Write("BusData.csv", outStr);

            webInterface_->UpdateBus(busses_[i]->GetBusData(), true);
            busses_.erase(busses_.begin() + i);
            continue;
        }
        
        webInterface_->UpdateBus(busses_[i]->GetBusData());

        busses_[i]->Report(std::cout);
    }
    
    std::cout << "~~~~~~~~~ Updating routes ";
    std::cout << "~~~~~~~~~" << std::endl;
    // Update routes
    for (int i = 0; i < static_cast<int>(prototypeRoutes_.size()); i++) {
        prototypeRoutes_[i]->Update();

        webInterface_->UpdateRoute(prototypeRoutes_[i]->GetRouteData());

        prototypeRoutes_[i]->Report(std::cout);
    }
 
}

void VisualizationSimulator::Pause() {
    if (!started) {
        return;
    }
    paused = !paused;
}

void VisualizationSimulator::ClearListeners() {
    // std::vector<Bus *> busses_;
    for(std::vector<IBus*>::const_iterator iter = busses_.begin(); iter != busses_.end(); ++iter)
    {
        (*iter)->ClearObserver();
    }
}

void VisualizationSimulator::AddListener(std::string * id, IObserver * observer) {
    for(std::vector<IBus*>::const_iterator iter = busses_.begin(); iter != busses_.end(); ++iter)
    {
        if((*iter)->GetBusData().id.compare(*id) == 0)
        {
            (*iter)->RegisterObserver(observer);
        }
    }
}