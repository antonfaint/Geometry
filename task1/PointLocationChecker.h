#ifndef POINTLOCATIONCHECKER_H
#define POINTLOCATIONCHECKER_H

#include "GeometryStructures.h"

class PointLocationChecker {
public:
    enum class PointLocation {INSIDE, OUTSIDE};
    enum class EdgeLocation {CROSSING, UNCROSSING, TOUCHING};

    PointLocationChecker(Polygon p): polygon(p) {}

    PointLocation checkPoint(Point & p);

    void setPolygon(Polygon p) {
        polygon = p;
    }

private:
    Polygon polygon;

    EdgeLocation edgeType(Point & p, Polygon::Edge & e);
};

#endif