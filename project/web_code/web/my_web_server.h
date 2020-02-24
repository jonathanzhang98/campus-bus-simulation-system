
#ifndef MY_WEB_SERVER_H
#define MY_WEB_SERVER_H

#include <vector>

#include "web_interface.h"


class MyWebServer : public WebInterface {
    
    public:
        MyWebServer();
        ~MyWebServer() {}

        void UpdateRoute(const RouteData& route, bool deleted = false) override;
        void UpdateBus(const BusData& bus, bool deleted = false) override;

        std::vector<RouteData> routes;
        std::vector<BusData> busses;

};

#endif //MY_WEB_SERVER_H
