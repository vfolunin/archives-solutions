#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

double globeDist(double lat1, double lon1, double lat2, double lon2) {
    static const double R = 6378;
    double angle = acos(min(max(sin(lat1) * sin(lat2) + cos(lat1) * cos(lat2) * cos(lon1 - lon2), -1.0), 1.0));
    return R * angle;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    map<string, int> vertexId;
    vector<double> lat, lon;
    static const double PI = 3.141592653589793;

    while (1) {
        string name;
        cin >> name;

        if (name == "#")
            break;

        vertexId[name] = vertexId.size();
        double degLat, degLon;
        cin >> degLat >> degLon;
        lat.push_back(degLat * PI / 180);
        lon.push_back(degLon * PI / 180);
    }

    while (1) {
        string sa, sb;
        cin >> sa >> sb;

        if (sa == "#" && sb == "#")
            break;

        cout << sa << " - " << sb << "\n";
        if (!vertexId.count(sa) || !vertexId.count(sb)) {
            cout << "Unknown\n";
        } else {
            int a = vertexId[sa], b = vertexId[sb];
            cout.precision(0);
            cout << fixed << globeDist(lat[a], lon[a], lat[b], lon[b]) << " km\n";
        }
    }
}