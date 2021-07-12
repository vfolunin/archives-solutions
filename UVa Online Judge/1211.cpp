#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int pointCount;
    cin >> pointCount;

    if (!pointCount)
        return 0;

    vector<int> pointCoord(pointCount + 1);
    for (int i = 1; i <= pointCount; i++)
        cin >> pointCoord[i];

    double changeTime, r, v, e, f;
    cin >> changeTime >> r >> v >> e >> f;

    vector<double> rideTime(pointCoord.back() + 1);
    for (int i = 0; i < rideTime.size(); i++)
        rideTime[i] = 1 / (v - (i < r ? f : e) * abs(r - i));
    for (int i = 1; i < rideTime.size(); i++)
        rideTime[i] += rideTime[i - 1];

    vector<double> resTime(pointCount + 1, 1e9);
    resTime[0] = 0;
    for (int i = 1; i <= pointCount; i++) {
        for (int j = 0; j < i; j++) {
            double curTime = resTime[j] + rideTime[pointCoord[i] - pointCoord[j] - 1];
            if (j != 0 && j != pointCount)
                curTime += changeTime;
            resTime[i] = min(resTime[i], curTime);
        }
    }

    cout.precision(4);
    cout << fixed << resTime.back() << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}