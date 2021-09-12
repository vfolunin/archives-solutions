#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

pair<bool, vector<int>> getStops(vector<int> &passengerFloors, int timeLimit) {
    vector<int> stops;
    int lastStop = 1, time = 0;

    for (int floor : passengerFloors) {
        if (time + (floor - lastStop) * 20 <= timeLimit)
            continue;

        if (lastStop > 1)
            time += 10;

        int stopFloor = floor;
        while (stopFloor < 31 && time + (stopFloor + 1 - lastStop) * 4 + (stopFloor + 1 - floor) * 20 <= timeLimit)
            stopFloor++;

        time += (stopFloor - lastStop) * 4;

        if (time > timeLimit)
            return { 0, {} };

        stops.push_back(stopFloor);
        lastStop = stopFloor;
    }

    return { 1, stops };
}

bool solve() {
    int passengerCount;
    cin >> passengerCount;

    if (!passengerCount)
        return 0;

    vector<int> passengerFloors(passengerCount);
    for (int &f : passengerFloors)
        cin >> f;

    int l = 0, r = 1000;
    while (l + 1 < r) {
        int m = l + (r - l) / 2;
        if (getStops(passengerFloors, m).first)
            r = m;
        else
            l = m;
    }

    vector<int> stops = getStops(passengerFloors, r).second;

    cout << r << "\n";
    cout << stops.size();
    for (int stop : stops)
        cout << " " << stop;
    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}