/**
 * @file bus_color_decorator.cc
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#include "src/bus_color_decorator.h"

BusData BusColorDecorator::GetBusData() const {
    BusData bus_data_ = bus->GetBusData();

    // Get the correct route and early exit
    Route * current_route = bus->GetOutgoingRoute();
    if (bus->GetOutgoingRoute()->IsAtEnd()) {
        if (bus->GetIncomingRoute()->IsAtEnd()) { return bus_data_; }
        current_route = bus->GetIncomingRoute();
    }

    // set color according to route
    if (current_route == bus->GetOutgoingRoute()) {
      Color outbound_color(128, 0, 0, 255);
      bus_data_.color = outbound_color;
        // bus_data_.color.red = 128;
        // bus_data_.color.green = 0;
        // bus_data_.color.blue = 0;
        // bus_data_.color.alpha = 255;
    } else {
        Color inbound_color(225, 215, 0, 255);
        bus_data_.color = inbound_color;
        // bus_data_.color.red = 128;
        // bus_data_.color.green = 0;
        // bus_data_.color.blue = 0;
        // bus_data_.color.alpha = 255;
    }

    return bus_data_;
}
