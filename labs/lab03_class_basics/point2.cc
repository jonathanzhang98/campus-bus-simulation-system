#include "point2.h"
#include <iostream>
#include <cmath>
using namespace std;

Point2::Point2(float _x, float _y) {
    x = _x;
    y = _y;
}

float Point2::DistanceBetween(const Point2& point) {
    float length, height;
    length = abs( this->x - point.x );
    height = abs( this->y - point.y ); 
    return sqrt(length * length + height * height);
}

void Point2::Print() {
    cout << "Point: ( " << x << ", " << y << " )" << endl;
}

int Point2::Quadrant() {
    int quadrant = 0;
    if (x > 0) {
        if (y >= 0) {
            quadrant = 1;
        } else {
            quadrant = 4;
        } 
    } else if (x < 0) {
        if (y > 0) {
            quadrant = 2;
        } else {
            quadrant = 3;
        }
    } else {
        if (y > 0) {
            quadrant = 2;
        } else if (y < 0) {
            quadrant = 4;
        } else {
            quadrant = 0;
        }
    }
    return quadrant;
}