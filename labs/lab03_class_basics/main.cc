// This follows the Google Style Guide:
//    https://google.github.io/styleguide/cppguide.html
// Style correctness verified by cpplint (pip install cpplint)

// Copyright 2018 <Amy C. Larson>

#include <iostream>
#include <fstream>
#include <string>
#include <time.h> // used for seeding rand()
#include <cstdlib>

#include "point2.h"

// Helper Functions Defined Below
void DisplayPoints(Point2 * cluster);
void DisplayTwoClosest(Point2 * cluster);
void DisplayFarthestFrom(Point2 point, Point2 * cluster);
void DisplayQuadrantCount(Point2 * cluster);

// Number of points in the cluster
const int point_count = 12;

int main() {

  Point2 origin;
  Point2 random_cluster[point_count];

  // Create random points within a 50x50 grid with (0,0) origin.
  int sign_x, sign_y;
  float x, y;
  srand(time(NULL));
  for (int i=0; i<point_count; i++) {
    sign_x = sign_y = 1;
    if (rand()%10 < 5) {
      sign_x = -1;
    }
    if (rand()%10 < 5) {
      sign_y = -1;
    }
    x = rand()%25 + rand()/(RAND_MAX+1.0);
    y = rand()%25 + rand()/(RAND_MAX+1.0);
    random_cluster[i] = Point2( x*sign_x, y*sign_y );
  }
  //std::cout << std::endl;
  DisplayPoints(random_cluster);
  DisplayTwoClosest(random_cluster);
  DisplayFarthestFrom(origin, random_cluster);
  DisplayQuadrantCount(random_cluster);

  return 0;
}

void DisplayTwoClosest(Point2 * cluster) {

  // Find the 2 closest points in the cluster.
  float min_distance_between = 1000;
  int index_a = -1;
  int index_b = -1;

  float distance;
  for (int i=0; i<point_count-1; i++) {
    for (int j=i+1; j<point_count; j++) {
      distance = cluster[i].DistanceBetween(cluster[j]);
      if (distance < min_distance_between) {
        min_distance_between = distance;
        index_a = i;
        index_b = j;
      }
    }
  }
  std::cout << "Of the cluster of points, ";
  cluster[index_a].Print();
  std::cout << " and ";
  cluster[index_b].Print();
  std::cout << " are the closest." << std::endl << std::endl;
}

void DisplayFarthestFrom(Point2 point, Point2 * cluster) {

  // Find the point farthest from point variable.
  float max_from_point = point.DistanceBetween(cluster[0]);
  int index = 0;
  float distance;
  for (int i=1; i<point_count; i++) {
    distance = point.DistanceBetween(cluster[i]);
    if (distance > max_from_point) {
      max_from_point = distance;
      index = i;
    }
  }
  std::cout << "Of the cluster of points, ";
  cluster[index].Print();
  std::cout << " is the farthest from ";
  point.Print();
  std::cout << std::endl << std::endl;
}

void DisplayQuadrantCount(Point2 * cluster) {

  // Determine how many points are in each quadrant
  int quad_count[4] = {0,0,0,0};
  for (int i=0; i<point_count; i++) {
    if (cluster[i].Quadrant() == 0)
      continue;
    // Point2.Quadrant() returns 1-4, but using it to index 0-3, thus -1
    quad_count[cluster[i].Quadrant()-1]++;
  }
  for (int i=0; i<4; i++) {
    std::cout << "Quadrant " << i+1 << " has " << quad_count[i] << " points.";
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

void DisplayPoints(Point2 * cluster) {
  std::cout << std::endl;
  for (int i=0; i<point_count; i++) {
    cluster[i].Print();
    std::cout << std::endl;
  }
  std::cout << std::endl;
}
