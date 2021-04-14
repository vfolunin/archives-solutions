#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Event {
    double coord;
    string type;
    double consumption;
};

bool can(vector<Event> &events, double fuel) {
    double prevCoord = 0, curConsumption = 0, curFuel = fuel, leaks = 0;

    for (auto &[coord, type, consumption] : events) {
        curFuel -= (coord - prevCoord) * (curConsumption + leaks);
        if (curFuel < 0)
            return 0;
        if (type == "consumption")
            curConsumption = consumption;
        if (type == "station")
            curFuel = fuel;
        if (type == "Mechanic")
            leaks = 0;
        if (type == "Leak")
            leaks++;
        prevCoord = coord;
    }

    return 1;
}

bool solve() {
    vector<Event> events;
    while (1) {
        events.emplace_back();
        cin >> events.back().coord >> events.back().type;
        if (events.back().type == "Fuel") {
            cin >> events.back().type >> events.back().consumption;
            events.back().consumption /= 100;
            if (!events.back().coord && !events.back().consumption)
                return 0;
        }
        if (events.back().type == "Gas")
            cin >> events.back().type;
        if (events.back().type == "Goal")
            break;
    }

    double l = 0, r = 1e9;
    for (int i = 0; i < 200; i++) {
        double m = (l + r) / 2;
        if (can(events, m))
            r = m;
        else
            l = m;
    }

    cout.precision(3);
    cout << fixed << l << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}