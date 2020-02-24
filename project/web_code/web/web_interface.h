
#ifndef WEB_INTERFACE_H
#define WEB_INTERFACE_H

#include "data_structs.h"
#include "bus.h"
#include "route.h"

class WebInterface {

public:
    virtual ~WebInterface() {}
    
    virtual void UpdateBus(const BusData& bus, bool deleted = false) = 0;
    virtual void UpdateRoute(const RouteData& route, bool deleted = false) = 0;

};

#endif // WEB_INTERFACE_H
