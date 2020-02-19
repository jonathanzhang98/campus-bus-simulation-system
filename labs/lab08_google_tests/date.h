/**
 * @file date.h
 *
 * @copyright 208 3081 Staff, All rights reserved.
 */

#ifndef SRC_DATE_H_
#define SRC_DATE_H_


/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief A simple representation of a date
 * It is stored as year, month, and day. Typically displayed as YYYY-MM-DD.
 */
 
class Date {
 public:
  /**
    * Constructors
  **/
  Date(void); //Current date
  Date(int year, int month, int day);

  /**
    * Constructor
    * param [in] epoch: an approximation of the number of seconds that have elapsed since 00:00:00 Coordinated Universal Time (UTC), Thursday, 1 January 1970
    *
    * Converts epoch time given to this Date format and stored.
    **/
  Date(int epoch);
  
  /**
    * Adding days to the date.
    * param [in] rhs: right hand side of this+rhs
    * param [out] New Date object representing the date which is "days" number of days after the date currently stored
    **/
  Date operator+(int days) const;

  /**
    * Subtracting days from the date.
    * param [in] rhs: right hand side of this+rhs
    * param [out] New Date object representing the date which is "days" number of days before the date currently stored
    **/
  Date operator-(int days) const;
  
  /**
    * Number of days between this date and the date provided
    * param [in] rhs: left hand side of this-rhs
    * param [out] number of days between the two dates
    **/
  int DaysBetween(const Date& date) const;
  
  /**
    * Accessor: Get the date as a string in YYYY-MM-DD format
    * param [out] Date formatted as a YYYY-MM-DD string
    **/
  std::string GetDate() const;

  /**
    * Accessor: Get the date as a string in MM-DD-YYY format
    * param [out] Date formatted as a MM-DD-YYYY string
    **/
  std::string GetUsDate() const;
  
  /**
    * Print the date in YYYY-MM-DD format
    * param [in] boolean flag, true: print newline, false: don't
    **/
  void PrintDate(bool newline) const;
  
  /**
    * Print the date in MM-DD-YYYY format
    * param [in] boolean flag, true: print newline, false: don't
    **/
  void PrintUsDate(bool newline) const;

 private:
  int yyyy_, mm_, dd_;
  int ConvertToDays(int yyyy, int mm, int dd) const;
  int * ConvertFromDays(int days) const;
  
};

#endif /* SRC_DATE_H_ */