/**
 * @file file_writer.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#ifndef SRC_FILE_WRITER_H_
#define SRC_FILE_WRITER_H_


/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <iostream>
#include <list>
#include <string>
#include <sstream>
#include <fstream>

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The main class for the large bus.
 *
 * 
 */
class FileWriter {
 public:
 
 /**
  * @brief Report the states of the bus.
  *
  * This function will be used for simulation purposes.
  *
  *
  * @return Report does not return anything.
  */
  void Write(std::string file_name, std::ostringstream& out);
 
 /**
  * @brief Report the states of the bus.
  *
  * This function will be used for simulation purposes.
  *
  *
  * @return Report does not return anything.
  */
  static FileWriter* GetInstance();

 private:
 /**
  * @brief Generation of a large bus.
  *
  * This function will be used for simulation purposes.
  *
  * @param[in] name
  * @param[in] out
  * @param[in] in
  * @param[in] speed
  *
  * @return Constructor does not return anything.
  */
//   FileWriter() {}

  static FileWriter *file_writer_;
};

#endif  // SRC_FILE_WRITER_H_
