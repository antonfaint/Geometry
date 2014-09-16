#include <iostream>
#include <vector>

#include "PointLocationChecker.h"

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main() {
    int n = 0;
    int m = 0;
    cin>> n;

    vector<Point> vertexList;
    for (int i = 0; i < n; ++i) {
        int x = 0;
        int y = 0;
        cin>> x >> y;
        vertexList.push_back(Point(x,y));
    }

    Polygon polygon(vertexList);
    PointLocationChecker checker(polygon);

    cin>> m;
    for (int j = 0; j < m; ++j) {
        int x = 0;
        int y = 0;
        cin>> x >> y;
        Point currentPoint(x,y);


        switch (checker.checkPoint(currentPoint)) {
            case PointLocationChecker::PointLocation::INSIDE :
                cout<< "YES"<< endl;
                break;
            default:
                cout<< "NO"<< endl;
                break;
        }

    }

    return 0;
}