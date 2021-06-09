#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int distance;
    string line;
    cin >> distance;    
    getline(cin, line);

    vector<pair<int, int>> stations;
    stations.push_back({ 0, 0 });
    while (1) {
        getline(cin, line);

        if (line.empty())
            break;

        stringstream ss(line);
        stations.emplace_back();
        ss >> stations.back().first >> stations.back().second;
    }
    while (stations.back().first > distance)
        stations.pop_back();
    stations.push_back({ distance, 0 });

    vector<vector<long long>> cost(stations.size(), vector<long long>(201, 1LL << 60));
    cost[0][100] = 0;

    for (int station = 1; station < stations.size(); station++) {
        for (int fuel = 0; fuel <= 200; fuel++) {
            for (int prevStation = 0; prevStation < station; prevStation++) {
                long long prevFuel = fuel + stations[station].first - stations[prevStation].first;
                if (prevFuel <= 200 && cost[station][fuel] > cost[prevStation][prevFuel])
                    cost[station][fuel] = cost[prevStation][prevFuel];
            }

            if (station + 1 < stations.size())
                for (int prevFuel = 0; prevFuel < fuel; prevFuel++)
                    cost[station][fuel] = min(cost[station][fuel], cost[station][prevFuel] + stations[station].second * (fuel - prevFuel));
        }
    }

    long long res = 1LL << 60;
    for (int fuel = 100; fuel <= 200; fuel++)
        res = min(res, cost.back()[fuel]);

    if (test)
        cout << "\n";
    if (res != 1LL << 60)
        cout << res << "\n";
    else
        cout << "Impossible\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve(i);
}