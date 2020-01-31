#ifndef POINT2_H
#define POINT2_H

class Point2 {
    public:
        Point2(float _x = 0, float _y = 0);
        float DistanceBetween(const Point2& rhs);
        void Print();
        int Quadrant();
    private:
        float x, y;
};

#endif