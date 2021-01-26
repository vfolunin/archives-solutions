#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> dijkstra(vector<vector<pair<int, int>>> &graph, int start) {
    vector<int> dist(1000, 1e9);
    dist[start] = 0;
    set<pair<int, int>> q = { {dist[start], start} };

    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());

        for (auto &[to, w] : graph[v]) {
            if (dist[to] > dist[v] + w) {
                q.erase({ dist[to], to });
                dist[to] = dist[v] + w;
                q.insert({ dist[to], to });
            }
        }
    }

    return dist;
}

bool solve() {
    int elevatorCount, targetFloor;
    if (!(cin >> elevatorCount >> targetFloor))
        return 0;

    vector<int> elevatorTime(elevatorCount);
    for (int &time : elevatorTime)
        cin >> time;

    vector<vector<pair<int, int>>> graph(1000);
    vector<vector<int>> elevators(100);

    for (int elevatorI = 0; elevatorI < elevatorCount; elevatorI++) {
        vector<int> floors;
        do {
            floors.emplace_back();
            cin >> floors.back();
            elevators[floors.back()].push_back(elevatorI);
        } while (cin.get() == ' ');

        for (int i = 0; i + 1 < floors.size(); i++) {
            int a = floors[i] * 10 + 1 + elevatorI;
            int b = floors[i + 1] * 10 + 1 + elevatorI;
            int time = (floors[i + 1] - floors[i]) * elevatorTime[elevatorI];
            graph[a].push_back({ b, time });
            graph[b].push_back({ a, time });
        }
    }

    for (int floorI = 0; floorI < 100; floorI++) {
        for (int elevatorI : elevators[floorI]) {
            int a = floorI * 10 + 1 + elevatorI;
            int b = floorI * 10;
            graph[a].push_back({ b, 60 });
            graph[b].push_back({ a, 0 });
        }
    }

    vector<int> dist = dijkstra(graph, 0);

    if (dist[targetFloor * 10] != 1e9)
        cout << max(0, dist[targetFloor * 10] - 60) << "\n";
    else
        cout << "IMPOSSIBLE\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}