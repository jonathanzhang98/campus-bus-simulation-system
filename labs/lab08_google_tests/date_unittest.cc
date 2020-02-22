#include "gtest/gtest.h"

#include <iostream>
#include <math.h>
#include <ctime>

#include "date.h"


class DateTest : public ::testing::Test {
 public:
  void SetUp( ) { 
    // code here will execute just before the test ensues 
	first_day = Date(2018, 9, 4);
	last_day = Date(2018, 12, 11);
  date_today = Date();
  leap1 = Date(2020, 2, 1);
  leap2 = Date(2020, 2, 29);
  leap3 = Date(2020, 3, 10);
  epoch = Date(0);
  class_start_epoch = Date(1536066000);
  }
 protected:
  Date first_day;          // first day of classes
  Date last_day;           // last day of classes
  Date date_today;
  Date leap1;
  Date leap2;
  Date leap3;
  Date epoch;
  Date class_start_epoch;
};

TEST_F(DateTest, DefaultConstructor) {
  std::time_t t = std::time(0);
  std::tm* now = std::localtime(&t);
  
  //tm year's value is years since 1900
  int yyyy_ = now->tm_year + 1900;
  //tm month's value is zero-indexed
  int mm_ = now->tm_mon + 1;
  //tm day's value is one-indexed
  int dd_ = now->tm_mday;

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

  EXPECT_EQ(date_today.GetDate(), date);
}

TEST_F(DateTest, PrintDateTests) {
  Date y2k(1999, 12, 31);              // y2k
  Date ind_day(1776, 7, 4);            // US Independence
  Date best_holiday(2018, 10, 31);     // Halloween
  
  std::string expected_out_1 = "1999-12-31\n";
  std::string expected_out_2 = "1776-07-04\n";
  std::string expected_out_3 = "2018-10-31\n";
  
  testing::internal::CaptureStdout();
  y2k.PrintDate(true);
  std::string output1 = testing::internal::GetCapturedStdout();
  
  testing::internal::CaptureStdout(); // You must do this EVERY TIME, or else it will segfault
  ind_day.PrintDate(true);
  std::string output2 = testing::internal::GetCapturedStdout();
  
  testing::internal::CaptureStdout();
  best_holiday.PrintDate(true);
  std::string output3 = testing::internal::GetCapturedStdout();
  
  EXPECT_EQ(output1, expected_out_1);
  EXPECT_EQ(output2, expected_out_2);
  EXPECT_EQ(output3, expected_out_3);
}

TEST_F(DateTest, PrintDateTestsWithoutNewline) {
  Date y2k(1999, 12, 31);              // y2k
  Date ind_day(1776, 7, 4);            // US Independence
  Date best_holiday(2018, 10, 31);     // Halloween
  
  std::string expected_out_1 = "1999-12-31";
  std::string expected_out_2 = "1776-07-04";
  std::string expected_out_3 = "2018-10-31";
  
  testing::internal::CaptureStdout();
  y2k.PrintDate(false);
  std::string output1 = testing::internal::GetCapturedStdout();
  
  testing::internal::CaptureStdout();
  ind_day.PrintDate(false);
  std::string output2 = testing::internal::GetCapturedStdout();
  
  testing::internal::CaptureStdout();
  best_holiday.PrintDate(false);
  std::string output3 = testing::internal::GetCapturedStdout();
  
  EXPECT_EQ(output1, expected_out_1);
  EXPECT_EQ(output2, expected_out_2);
  EXPECT_EQ(output3, expected_out_3);
}

TEST_F(DateTest, PrintUsDateTests) { 
  Date y2k(1999, 12, 31);              // y2k
  Date ind_day(1776, 7, 4);            // US Independence
  Date best_holiday(2018, 10, 31);     // Halloween
  
  std::string expected_out_1 = "12-31-1999\n";
  std::string expected_out_2 = "07-04-1776\n";
  std::string expected_out_3 = "10-31-2018\n";
  
  testing::internal::CaptureStdout();
  y2k.PrintUsDate(true);
  std::string output1 = testing::internal::GetCapturedStdout();
  
  testing::internal::CaptureStdout(); // You must do this EVERY TIME, or else it will segfault
  ind_day.PrintUsDate(true);
  std::string output2 = testing::internal::GetCapturedStdout();
  
  testing::internal::CaptureStdout();
  best_holiday.PrintUsDate(true);
  std::string output3 = testing::internal::GetCapturedStdout();
  
  EXPECT_EQ(output1, expected_out_1);
  EXPECT_EQ(output2, expected_out_2);
  EXPECT_EQ(output3, expected_out_3);
}

TEST_F(DateTest, PrintUsDateTestsWithoutNewline) {
  Date y2k(1999, 12, 31);              // y2k
  Date ind_day(1776, 7, 4);            // US Independence
  Date best_holiday(2018, 10, 31);     // Halloween
  
  std::string expected_out_1 = "12-31-1999";
  std::string expected_out_2 = "07-04-1776";
  std::string expected_out_3 = "10-31-2018";
  
  testing::internal::CaptureStdout();
  y2k.PrintUsDate(false);
  std::string output1 = testing::internal::GetCapturedStdout();
  
  testing::internal::CaptureStdout();
  ind_day.PrintUsDate(false);
  std::string output2 = testing::internal::GetCapturedStdout();
  
  testing::internal::CaptureStdout();
  best_holiday.PrintUsDate(false);
  std::string output3 = testing::internal::GetCapturedStdout();
  
  EXPECT_EQ(output1, expected_out_1);
  EXPECT_EQ(output2, expected_out_2);
  EXPECT_EQ(output3, expected_out_3);
}

/**
  *
  * Note, this is the only provided test case which actually uses our test fixture
  * 
  * However, it is illegal to mix TEST() and TEST_F() in the same test case (file).
  *
  */

TEST_F(DateTest, operatorPlusTests) {
  EXPECT_EQ(first_day.operator+(10).GetDate(), "2018-09-14");
  EXPECT_EQ(last_day.operator+(5).GetDate(), "2018-12-16");
  EXPECT_EQ(leap1.operator+(28).GetDate(), "2020-02-29");
  EXPECT_EQ(leap1.operator+(30).GetDate(), "2020-03-02");
}

TEST_F(DateTest, operatorMinusTests) {
  EXPECT_EQ(first_day.operator-(5).GetDate(), "2018-08-30");
  EXPECT_EQ(last_day.operator-(10).GetDate(), "2018-12-01");
  EXPECT_EQ(leap3.operator-(10).GetDate(), "2020-02-29");
  EXPECT_EQ(leap3.operator-(15).GetDate(), "2020-02-24");
}

TEST_F(DateTest, DaysBetweenTests) {
  EXPECT_EQ(first_day.GetUsDate(), "09-04-2018") << "First day of class not setup properly";
  EXPECT_EQ(last_day.GetUsDate(), "12-11-2018") << "Last day of class not setup properly";
  EXPECT_EQ(first_day.DaysBetween(last_day), 98) << "Days between is not calculated properly";
  EXPECT_EQ(leap1.DaysBetween(leap2), 28) << "Days between is not calculated properly";
  EXPECT_EQ(leap1.DaysBetween(leap3), 38) << "Days between is not calculated properly";
  EXPECT_EQ(leap2.DaysBetween(leap3), 10) << "Days between is not calculated properly";
  EXPECT_EQ(epoch.DaysBetween(class_start_epoch), 17778) << "Days between is not calculated properly";
}

TEST_F(DateTest, GetDateTests) {
  EXPECT_EQ(first_day.GetDate(), "2018-09-04") << "First day of class not setup properly";
  EXPECT_EQ(last_day.GetDate(), "2018-12-11") << "Last day of class not setup properly";
  EXPECT_EQ(leap1.GetDate(), "2020-02-01") << "Leap1 day of class not setup properly";
  EXPECT_EQ(leap2.GetDate(), "2020-02-29") << "Leap2 day of class not setup properly";
  EXPECT_EQ(leap3.GetDate(), "2020-03-10") << "Leap3 day of class not setup properly";
  EXPECT_EQ(epoch.GetDate(), "1970-01-01") << "Epoch day of class not setup properly";
  EXPECT_EQ(class_start_epoch.GetDate(), "2018-09-04") << "Class start epoch day of class not setup properly";
}

TEST_F(DateTest, GetUsDateTests) {
  EXPECT_EQ(first_day.GetUsDate(), "09-04-2018") << "First day of class not setup properly";
  EXPECT_EQ(last_day.GetUsDate(), "12-11-2018") << "Last day of class not setup properly";
  EXPECT_EQ(leap1.GetUsDate(), "02-01-2020") << "Leap1 day of class not setup properly";
  EXPECT_EQ(leap2.GetUsDate(), "02-29-2020") << "Leap2 day of class not setup properly";
  EXPECT_EQ(leap3.GetUsDate(), "03-10-2020") << "Leap3 day of class not setup properly";
  EXPECT_EQ(epoch.GetUsDate(), "01-01-1970") << "Epoch day of class not setup properly";
  EXPECT_EQ(class_start_epoch.GetUsDate(), "09-04-2018") << "Class start epoch day of class not setup properly";
}

/**
  *
  * NOPE!  Can't test PRIVATE methods
  *
  */
/*
TEST(DateTest, ConvertFromDays) {
	Date convert_first_day = ConvertToDays(2458365);
	EXPECT_STREQ(convert_first_day.GetUsDate(), "09-04-2018");
}
*/
