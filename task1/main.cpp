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
        long int x = 0, y = 0;
        char c1, c2, c3;
        cin>>c1 >> x >> c2 >> y >> c3;

        vertexList.push_back(Point(x,y));
    }

    Polygon polygon(vertexList);
    PointLocationChecker checker(polygon);

    cin>> m;

    for (int j = 0; j < m; ++j) {
        long int x = 0, y = 0;
        char c1, c2, c3;
        cin>>c1 >> x >> c2 >> y >> c3;

        Point currentPoint(x,y);

        try {
            switch (checker.checkPoint(currentPoint)) {
                case PointLocationChecker::PointLocation::INSIDE :
                    cout<< "yes"<< endl;
                    break;
                default:
                    cout<< "no"<< endl;
                    break;
            }
        } catch (std::runtime_error const e){
            cout<<e.what()<<endl;

        }


    }

    return 0;
}