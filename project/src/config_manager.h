/**
 * @file passenger_unloader.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */

#ifndef SRC_CONFIG_MANAGER_H_
#define SRC_CONFIG_MANAGER_H_


/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <vector>
#include <string>


class Route;

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The main class for the configuration of the simulation.
 *
 * Calls to \ref Generate function to get a new instance of a passenger.
 *  This is a static call, not requiring an instance to invoke the method.
 */
class ConfigManager {
 public:
  /**
   * @brief Generates a ConfigManager obejct.
   *
   * This function will be used for simulation purposes.
   *
   * @return Constructor does not return anything.
   */
    ConfigManager();

  /**
   * @brief Destructs a ConfigManager object.
   *
   * This function will be used for simulation purposes.
   *
   * @return Destructor does not return anything.
   */
    ~ConfigManager();

  /**
   * @brief Load a passenger onto the bus.
   *
   * This function will be used for simulation purposes.
   *
   * @param[in] filename 
   *
   * @return ReadConfig does not return anything.
   */
    void ReadConfig(const std::string filename);

  /**
   * @brief Load a passenger onto the bus.
   *
   * This function will be used for simulation purposes.
   *
   *
   * @return GetRoutes returns routes.
   */
    std::vector<Route *> GetRoutes() const { return routes; }

 private:
    std::vector<Route *> routes;
};

#endif  // SRC_CONFIG_MANAGER_H_
