/**
 * @file bus_color_decorator.cc
 *
 * @copyright 2020 Zixuan Zhang, All rights reserved.
 */
#include "src/bus_intensity_decorator.h"

BusData BusIntensityDecorator::GetBusData() const {
    BusData bus_data_ = bus->GetBusData();

    int num_passengers = bus->GetNumPassengers();
    int alpha;
    if (num_passengers <= 3) {
        alpha = 120;
    } else if (num_passengers <= 8) {
        alpha = 200;
    } else {
        alpha = 255;
    }

    bus_data_.color.alpha = alpha;

    return bus_data_;
}
