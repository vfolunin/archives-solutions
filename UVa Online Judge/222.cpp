#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const double EPS = 1e-9;

double roundToCents(double cost) {
    return round(cost * 100) / 100;
}

struct Solver {
    double capacity, milesPerGallon, startCost, minCost;
    vector<pair<double, double>> stations;

    void rec(int i, double fuel, double cost) {
        if (i == stations.size()) {
            minCost = min(minCost, cost);
            return;
        }
        
        double curDistance = stations[i].first - (i ? stations[i - 1].first : 0);
        double needFuel = curDistance / milesPerGallon;

        if (fuel + EPS < needFuel) {
            rec(i + 1, capacity - needFuel, cost + roundToCents(stations[i - 1].second * (capacity - fuel)) + 2);
        } else if (fuel * 2 > capacity + EPS) {
            rec(i + 1, fuel - needFuel, cost);
        } else {
            rec(i + 1, capacity - needFuel, cost + roundToCents(stations[i - 1].second * (capacity - fuel)) + 2);
            rec(i + 1, fuel - needFuel, cost);
        }
    }

    double getMinCost() {
        minCost = 1e9;
        rec(0, capacity, startCost);
        return minCost;
    }
};

bool solve(int test) {
    double distance;
    cin >> distance;

    if (distance < 0)
        return 0;

    Solver solver;
    int stationCount;
    cin >> solver.capacity >> solver.milesPerGallon >> solver.startCost >> stationCount;

    solver.stations.resize(stationCount);
    for (auto &[coord, cost] : solver.stations) {
        cin >> coord >> cost;
        cost /= 100;
    }
    solver.stations.push_back({ distance, 1e9 });

    cout << "Data Set #" << test << "\n";
    cout.precision(2);
    cout << "minimum cost = $" << fixed << solver.getMinCost() << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}