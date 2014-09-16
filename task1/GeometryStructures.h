#ifndef GEOMETRYSTRUCTURES_H
#define GEOMETRYSTRUCTURES_H

#include <math.h>
#include <vector>
#include <stdexcept>

using std::vector;

struct Point {
    int x;
    int y;
    enum class PointType {LEFT, RIGHT, AHEAD, BEHIND, BETWEEN, START, END};

    Point(int x, int y) : x(x), y(y) {}
    Point operator+(Point& p) {
        return Point(x + p.x, y + p.y);
    }
    Point operator-(Point& p) {
        return Point(x - p.x, y - p.y);
    }
    int operator==(Point& p) {
        return (x == p.x) && (y == p.y);
    }

    double length() {
        return sqrt(x*x+ y*y);
    }

    PointType classify(Point & p1, Point & p2);



};

class Polygon {
public:

    struct Edge {
        Point start;
        Point end;

        Edge(Point p1, Point p2): start(p1), end(p2){}
    };

    Polygon(vector<Point>& vList): vertexList(vList){};

    int size() {
        return vertexList.size();
    };

    Edge getEdge(int i) {
        if (i < vertexList.size() && i + 1 < vertexList.size()) {
            return Edge(vertexList.at(i), vertexList.at(i + 1));
        }
        throw std::runtime_error("Edge not avalable");
    }


private:
    vector<Point> vertexList;
};

#endif
