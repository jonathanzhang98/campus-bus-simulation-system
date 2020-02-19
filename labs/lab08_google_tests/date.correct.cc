/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <cmath>     // Used for absolute value (abs)
#include <iostream>
#include <string>
#include <cstdio>    // Used for sprintf, converting int to string
#include <iomanip>   // Used to print leading zeroes for month, day
#include <ctime>     // Used to get current date

#include "date.h"

Date::Date(void) {
  std::time_t t = std::time(0);
  std::tm* now = std::localtime(&t);
  
  //tm year's value is years since 1900
  yyyy_ = now->tm_year + 1900;
  //tm month's value is zero-indexed
  mm_ = now->tm_mon + 1;
  //tm day's value is one-indexed
  dd_ = now->tm_mday;
}

Date::Date(int year, int month, int day) {
  yyyy_ = year;
  mm_ = month;
  dd_ = day;
}

/**
* Constructor
* param [in] epoch: an approximation of the number of seconds that have elapsed since 00:00:00 Coordinated Universal Time (UTC), Thursday, 1 January 1970
*
* Converts epoch time given to this Date format. Uses C std gmtime to convert epoch time to tm structure
**/
Date::Date(int epoch) {
  std::time_t epoch_t = epoch;
  std::tm* yyyy_mm_dd = std::gmtime( &epoch_t );
  
  //tm year's value is years since 1900
  yyyy_ = yyyy_mm_dd->tm_year + 1900;
  //tm month's value is zero-indexed
  mm_ = yyyy_mm_dd->tm_mon + 1;
  //tm day's value is one-indexed
  dd_ = yyyy_mm_dd->tm_mday;
}

/**
* Adding days to the date.
* param [in] rhs: right hand side of this+rhs
* param [out] New Date object representing the date which is "days" number of days after the date currently stored
* MUTATION : THIS VERSION DOES NOT TAKE LEAP YEAR INTO ACCOUNT
**/
Date Date::operator+(int days) const {
  int old_date = ConvertToDays(yyyy_, mm_, dd_);
  //std::cout << "Debugging ConvertToDays: " << old_date << std::endl;
  int * new_date = ConvertFromDays(old_date + days);
  //std::cout << "Debugging ConvertFromDays: " << std::endl;
  //std::cout << old_date << " + " << days << " = ";
  return Date(new_date[0], new_date[1], new_date[2]);
}

/**
* Subtracting days from the date.
* param [in] rhs: right hand side of this+rhs
* param [out] New Date object representing the date which is "days" number of days before the date currently stored
**/
Date Date::operator-(int days) const{
  int old_date = ConvertToDays(yyyy_, mm_, dd_);
  int * new_date = ConvertFromDays(old_date - days);
  return Date(new_date[0], new_date[1], new_date[2]);
}

/**
* Number of days between this date and the date provided
* param [in] rhs: left hand side of this-rhs
* param [out] number of days between the two dates (always positive)
**/
int Date::DaysBetween(const Date& date) const {
  int this_days = ConvertToDays(yyyy_, mm_, dd_);
  //std::cout << "Debugging ConvertToDays (LHS): " << this_days << std::endl;
  int that_days = ConvertToDays(date.yyyy_, date.mm_, date.dd_);
  //std::cout << "Debugging ConvertToDays: (RHS)" << that_days << std::endl;
  return std::abs(this_days - that_days);
}

/**
* Accessor: Get the date as a string in YYYY-MM-DD format
* param [out] Date formatted as a YYYY-MM-DD string
**/
std::string Date::GetDate() const {
  char numstr[5]; //large enough for years, months, days
  std::string date = "";
  sprintf(numstr, "%d", yyyy_);
  date = date + numstr + "-";
  if (mm_ < 10)
    date = date + "0";
  sprintf(numstr, "%d", mm_);
  date = date + numstr + "-";
  if (dd_ < 10)
    date = date + "0";
  sprintf(numstr, "%d", dd_);
  date = date + numstr;
  return date;
}

/**
* Accessor: Get the date as a string in MM-DD-YYY format
* param [out] Date formatted as a MM-DD-YYYY string
**/
std::string Date::GetUsDate() const {
  char numstr[5]; //large enough for years, months, days

  std::string date;
  if (mm_ < 10)
    date = date + "0";
  sprintf(numstr, "%d", mm_);
  date = date + numstr + "-";
  if (dd_ < 10)
    date = date + "0";
  sprintf(numstr, "%d", dd_);
  date = date + numstr;
  sprintf(numstr, "%d", yyyy_);
  date = date + "-" + numstr;
  return date;
}

/**
* Print the date in YYYY-MM-DD format
* param [in] boolean flag, true: print newline, false: don't
**/
void Date::PrintDate(bool newline) const {
  std::cout << yyyy_ << "-" << std::setw(2) << std::setfill('0') << mm_ << "-" << std::setw(2) << std::setfill('0') << dd_;
  if (newline)
    std::cout << std::endl;
}

/**
* Print the date in MM-DD-YYYY format
* param [in] boolean flag, true: print newline, false: don't
**/
void Date::PrintUsDate(bool newline) const {
  std::cout << std::setw(2) << std::setfill('0') << mm_ << "-" << std::setw(2) << std::setfill('0') << dd_ << "-" << yyyy_;
  if (newline)
    std::cout << std::endl;
}


/*******************************************************************************
 * Private methods
 ******************************************************************************/

 /**
   *
   * Both of these are from
   *   https://www.hermetic.ch/cal_stud/jdn.htm#comp
   *
   */
   
int Date::ConvertToDays(int yyyy, int mm, int dd) const{
  return ( 1461 * ( yyyy + 4800 + ( mm - 14 ) / 12 ) ) / 4 +
          ( 367 * ( mm - 2 - 12 * ( ( mm - 14 ) / 12 ) ) ) / 12 -
          ( 3 * ( ( yyyy + 4900 + ( mm - 14 ) / 12 ) / 100 ) ) / 4 +
          dd - 32075;
}

int * Date::ConvertFromDays(int days) const{
  int * date_back = new int[3];
  int l = days + 68569;
  int n = ( 4 * l ) / 146097;
  l = l - ( 146097 * n + 3 ) / 4;
  int i = ( 4000 * ( l + 1 ) ) / 1461001;
  l = l - ( 1461 * i ) / 4 + 31;
  int j = ( 80 * l ) / 2447;
  date_back[2] = l - ( 2447 * j ) / 80;
  l = j / 11;
  date_back[1] = j + 2 - ( 12 * l );
  date_back[0] = 100 * ( n - 49 ) + i + l;
  return date_back;
}
