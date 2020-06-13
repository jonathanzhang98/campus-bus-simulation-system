/**
 * @file file_writer.h
 *
 * @copyright 2020 Zixuan Zhang, All rights reserved.
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
  * @brief Write the ostring stream to file.
  *
  * This function will be used for simulation purposes.
  *
  *
  * @return Write the ostring stream to file.
  */
  void Write(std::string file_name, std::ostringstream& out);

 /**
  * @brief Get the singleton instance.
  *
  * This function will be used for simulation purposes.
  *
  *
  * @return GetInstance does not return the singleton instance.
  */
  static FileWriter* GetInstance();

 private:
  static FileWriter *file_writer_;
};

#endif  // SRC_FILE_WRITER_H_
