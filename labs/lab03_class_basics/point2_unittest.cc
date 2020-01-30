#include "gtest/gtest.h"
#include <iostream>
#include <math.h>
#include "point2.h"


class Point2Test : public ::testing::Test {
  void SetUp( ) {
    // code here will execute just before the test ensues
	//Point2 p00;
	p11 = Point2(1.0, 1.0);
	p21 = Point2(2.0, 1.0);
	p12 = Point2(1.0, 2.0);
	pPI45 = Point2(sqrt(2)/2, sqrt(2)/2);
	p_a = Point2(3.0, 5.0);
	p_b = Point2(4.0, 4.0);

  // For testing Quadrant()
  p_q1 = Point2(1,1);
  p_q2 = Point2(-1,1);
  p_q3 = Point2(-1,-1);
  p_q4 = Point2(1,-1);
  p_q1_border = Point2(1,0);
  p_q2_border = Point2(0,1);
  p_q3_border = Point2(-1,0);
  p_q4_border = Point2(0,-1);
  }

protected:
  Point2 p00;
	Point2 p11;
	Point2 p21;
	Point2 p12;
	Point2 pPI45;
	Point2 p_a;
	Point2 p_b;
  Point2 p_q1;
  Point2 p_q2;
  Point2 p_q3;
  Point2 p_q4;
  Point2 p_q1_border;
  Point2 p_q2_border;
  Point2 p_q3_border;
  Point2 p_q4_border;
};

TEST_F(Point2Test, DistBtwnBothPositive) {
  EXPECT_FLOAT_EQ(p11.DistanceBetween(p21), 1.0);
  EXPECT_FLOAT_EQ(p21.DistanceBetween(p12), sqrt(2));
  EXPECT_FLOAT_EQ(p00.DistanceBetween(pPI45), 1.0);
  EXPECT_FLOAT_EQ(p_a.DistanceBetween(p_b), sqrt(2));
}

TEST_F(Point2Test, DistBtwnInverses) {
  EXPECT_FLOAT_EQ(p11.DistanceBetween(p21), p21.DistanceBetween(p11));
  EXPECT_FLOAT_EQ(p21.DistanceBetween(p12), p12.DistanceBetween(p21));
  EXPECT_FLOAT_EQ(p00.DistanceBetween(pPI45), pPI45.DistanceBetween(p00));
  EXPECT_FLOAT_EQ(p_a.DistanceBetween(p_b), p_b.DistanceBetween(p_a));
}

TEST_F(Point2Test, Quadrant) {
  EXPECT_EQ(p00.Quadrant(),0);
  EXPECT_EQ(p_q1.Quadrant(),1);
  EXPECT_EQ(p_q2.Quadrant(),2);
  EXPECT_EQ(p_q3.Quadrant(),3);
  EXPECT_EQ(p_q4.Quadrant(),4);
}

TEST_F(Point2Test, QuadrantBorder) {
  EXPECT_EQ(p_q1_border.Quadrant(),1);
  EXPECT_EQ(p_q2_border.Quadrant(),2);
  EXPECT_EQ(p_q3_border.Quadrant(),3);
  EXPECT_EQ(p_q4_border.Quadrant(),4);
}
