#include "PointLocationChecker.h"

PointLocationChecker::PointLocation PointLocationChecker::checkPoint(Point& p) {
    int parity = 0;
    int currentEdgeNum = 0;

    while(currentEdgeNum < polygon.size() - 1) {

        Polygon::Edge currentEdge = polygon.getEdge(currentEdgeNum);
        switch (edgeType(p, currentEdge)) {
            case PointLocationChecker::EdgeLocation::TOUCHING:
                return PointLocationChecker::PointLocation::INSIDE;
            case PointLocationChecker::EdgeLocation::CROSSING:
                parity = 1 - parity;
        }
        ++currentEdgeNum;
    }
    return (parity ? PointLocationChecker::PointLocation::INSIDE :
            PointLocationChecker::PointLocation::OUTSIDE);


}

PointLocationChecker::EdgeLocation PointLocationChecker::edgeType(Point &p, Polygon::Edge &e) {
    switch (p.classify(e.start, e.end)) {
        case Point::PointType::LEFT:
            return ((e.start.y < p.y)&&(p.y <= e.end.y) ?
                    PointLocationChecker::EdgeLocation::CROSSING:
                    PointLocationChecker::EdgeLocation::UNCROSSING
            );
        case Point::PointType::RIGHT:
            return ((e.end.y < p.y)&&(p.y <= e.start.y) ?
                    PointLocationChecker::EdgeLocation::CROSSING:
                    PointLocationChecker::EdgeLocation::UNCROSSING
            );
        case Point::PointType::BETWEEN:
        case Point::PointType::START:
        case Point::PointType::END:
            return PointLocationChecker::EdgeLocation::TOUCHING;
        default:
            return PointLocationChecker::EdgeLocation::UNCROSSING;
    }
}