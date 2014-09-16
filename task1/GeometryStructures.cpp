#include "GeometryStructures.h"

Point::PointType Point::classify(Point &p1, Point &p2) {
    Point a = p2 - p1;
    Point b = *this - p1;

    int s = a.x * b.y - b.x * a.y;
    if (s < 0) {
        return PointType::LEFT;
    }
    if (s > 0) {
        return PointType::RIGHT;
    }
    if ((a.x * b.x < 0) || (a.y * b.y < 0)) {
        return PointType::BEHIND;
    }
    if (a.length() < b.length()) {
        return PointType::AHEAD;
    }
    if (*this == p1) {
        return PointType::START;
    }
    if (*this == p2) {
        return PointType::END;
    }

    return PointType::BETWEEN;

}