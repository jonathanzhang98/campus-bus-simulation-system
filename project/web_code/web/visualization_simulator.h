
#ifndef VISUALIZATION_SIMULATOR_H_
#define VISUALIZATION_SIMULATOR_H_

#include <vector>
#include <list>

#include "web_interface.h"
#include "config_manager.h"
#include "src/concrete_bus_factory.h"
#include "src/i_observable.h"
#include "src/i_observer.h"

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
        void ClearListeners();
        void AddListener(std::string *, IObserver *);

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
        std::vector<Bus *> busses_;

        int busId = 1000;
};

#endif // VISUALIZATION_SIMULATOR_H_
