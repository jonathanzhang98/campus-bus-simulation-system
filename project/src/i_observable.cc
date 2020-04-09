/**
 * @file i_observer.cc
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */

#include "src/i_observable.h"
#include <vector>
#include <list>
#include <algorithm>
#include <iostream>
#include <string>

void IObservable::RegisterObserver(IObserver * observer) {
  observer_.push_back(observer);
}

void IObservable::ClearObserver() {
  observer_.erase(observer_.begin(), observer_.end());
}

void IObservable::NotifyObserver(BusData * bus_data) {
  for(std::vector<IObserver*>::const_iterator iter = observer_.begin(); iter != observer_.end(); ++iter)
    {
        if(*iter != 0)
        {
            (*iter)->UpdateObserver(bus_data);
        }
    }
}
