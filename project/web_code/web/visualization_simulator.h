
#ifndef VISUALIZATION_SIMULATOR_H_
#define VISUALIZATION_SIMULATOR_H_

#include <vector>
#include <list>

#include "web_interface.h"
#include "config_manager.h"
#include "src/concrete_bus_factory.h"
#include "src/i_observable.h"
#include "src/i_observer.h"
#include "src/i_bus.h"
#include "src/bus_decorator.h"
#include "src/bus_color_decorator.h"
#include "src/bus_intensity_decorator.h"
#include "bus.h"
#include "route.h"

#include <vector>
#include <random>
#include <string>



class Route;
class Bus;
class Stop;

class VisualizationSimulator {
    public:
        VisualizationSimulator(WebInterface*, ConfigManager*);
        ~VisualizationSimulator();

        void Start(const std::vector<int>&, const int&);
        void Update();

       /**
        * @brief Pause the simulation by not updating.
        *
        * This function will be used for simulation purposes.
        *
        *
        * @return Pause does not return anything.
        */
        void Pause();
        void ClearBusListeners();
        void ClearStopListeners();
        void AddBusListener(std::string * id, IObserver<BusData> * observer) {
            for(std::vector<IBus*>::const_iterator iter = busses_.begin(); iter != busses_.end(); ++iter)
            {
                if((*iter)->GetBusData().id.compare(*id) == 0)
                {
                    (*iter)->RegisterObserver(observer);
                }
            }
        }
        void AddStopListener(std::string * id, IObserver<StopData> * observer) {
            for(std::vector<Route*>::const_iterator route_iter = prototypeRoutes_.begin(); route_iter != prototypeRoutes_.end(); ++route_iter) {
                std::list<Stop*> stops = (*route_iter)->GetStops();
                for(std::list<Stop*>::const_iterator iter = stops.begin(); iter != stops.end(); ++iter)
                {
                    if((*iter)->GetId() == std::stoi(*id))
                    {
                        (*iter)->RegisterObserver(observer);
                    }
                }
            }
        }

    private:
        WebInterface* webInterface_;
        ConfigManager* configManager_;
       
        std::vector<int> busStartTimings_;
        std::vector<int> timeSinceLastBus_;
        int numTimeSteps_;
        int simulationTimeElapsed_;
        bool paused;
        bool started = false;

        std::vector<Route *> prototypeRoutes_;
        std::vector<IBus *> busses_;

        int busId = 1000;
};

#endif // VISUALIZATION_SIMULATOR_H_
