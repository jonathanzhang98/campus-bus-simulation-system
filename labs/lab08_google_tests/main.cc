/**
 * @file main.cc
 *
 * @copyright 2018 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <iostream>
#include <string>

#include "date.h"

int main(int, char **) {
  Date date_today;
  Date y2k(1999, 12, 31);              // y2k
  Date first_day(2018, 9, 4);          // first day of classes
  Date last_day(2018, 12, 11);         // last day of classes
  Date ind_day(1776, 7, 4);            // US Independence
  Date best_holiday(2018, 10, 31);     // Halloween
  Date epoch(0);				 	   // epoch day (1970-01-01)
  Date class_start_epoch(1536066000);  // 2018-09-04 13:00:00
  
  /**
    *
	*  Print some dates
	*
	**/
  
  std::cout << "Today's Date: " << std::endl;
  date_today.PrintDate(true);
  date_today.PrintUsDate(true);
  
  std::cout << "Y2K: " << std::endl;
  y2k.PrintDate(true);
  y2k.PrintUsDate(true);
  
  std::cout << "First Day of Class: " << std::endl;
  first_day.PrintDate(true);
  first_day.PrintUsDate(true);
  
  std::cout << "Last Day of Class: " << std::endl;
  last_day.PrintDate(true);
  last_day.PrintUsDate(true);
  
  std::cout << "US Independence Day: " << std::endl;
  ind_day.PrintDate(true);
  ind_day.PrintUsDate(true);
  
  std::cout << "Best Holiday: " << std::endl;
  best_holiday.PrintDate(true);
  best_holiday.PrintUsDate(true);

  std::cout << "Epoch: " << std::endl;
  epoch.PrintDate(true);
  epoch.PrintUsDate(true);
  
  std::cout << "Class start time (using epoch): " << std::endl;
  class_start_epoch.PrintDate(true);
  class_start_epoch.PrintUsDate(true);
  
  /**
    *
	*  Get some dates
	*
	**/
  
  std::cout << "Today's Date: " << std::endl;
  std::cout << date_today.GetDate() << std::endl;
  std::cout << date_today.GetUsDate() << std::endl; 
  
  std::cout << "Y2K: " << std::endl;
  std::cout << y2k.GetDate() << std::endl;
  std::cout << y2k.GetUsDate() << std::endl; 
  
  std::cout << "First Day of Class: " << std::endl;
  std::cout << first_day.GetDate() << std::endl;
  std::cout << first_day.GetUsDate() << std::endl; 
  
  /**
    *
	*  Perform some operations
	*
	**/
  
  Date answer_day;
  int answer_num_days;

  std::cout << "Length of semester in days: " << std::endl;
  answer_num_days = first_day.DaysBetween(last_day);
  std::cout << answer_num_days << std::endl;

  std::cout << "First day plus days between: " << std::endl;
  answer_day = first_day + answer_num_days;
  answer_day.PrintDate(true);
  
  std::cout << "Day after Y2K" << std::endl;
  answer_day = y2k + 1;
  answer_day.PrintDate(true);
  
  std::cout << "Tomorrow (using today + 1): " << std::endl;
  Date tomorrow = date_today + 1;
  tomorrow.PrintDate(true);
  tomorrow.PrintUsDate(true);  

  std::cout << "Independence Eve (using ind_day - 1): " << std::endl;
  answer_day = ind_day - 1;
  answer_day.PrintDate(true);

  return 0;
}
