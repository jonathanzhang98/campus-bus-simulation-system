/**
 * @file file_writer.cc
 *
 * @copyright 2020 Zixuan Zhang, All rights reserved.
 */

#include "src/file_writer.h"
#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

FileWriter* FileWriter::file_writer_ = nullptr;

FileWriter* FileWriter::GetInstance() {
  if (!file_writer_) {
      file_writer_ = new FileWriter();
  }
  return file_writer_;
}

void FileWriter::Write(std::string file_name, std::ostringstream& out) {
  ofstream outfile(file_name, std::ios_base::app);
  outfile << out.str() << '\n';
  outfile.close();
}
