#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void dijkstra(vector<vector<pair<int, int>>> &graph, const vector<int> &start, vector<int> &dist) {
    set<pair<int, int>> q;

    for (int v : start) {
        dist[v] = 0;
        q.insert({ dist[v], v });
    }

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
}

void solve(int test) {
    int fireStationCount, vertexCount;
    cin >> fireStationCount >> vertexCount;

    vector<int> fireStations(fireStationCount);
    for (int &f : fireStations) {
        cin >> f;
        f--;
    }
    sort(fireStations.begin(), fireStations.end());

    vector<vector<pair<int, int>>> graph(vertexCount);
    cin.ignore();
    while (1) {
        string line;
        if (!getline(cin, line) || line.empty())
            break;
        stringstream ss(line);
        int a, b, w;
        ss >> a >> b >> w;
        a--;
        b--;
        graph[a].push_back({ b, w });
        graph[b].push_back({ a, w });
    }

    vector<int> dist(vertexCount, 1e9);
    dijkstra(graph, fireStations, dist);
    int bestD = 1e9, bestV = -1;

    for (int v = 0; v < vertexCount; v++) {
        if (v && binary_search(fireStations.begin(), fireStations.end(), v))
            continue;

        vector<int> curDist = dist;
        curDist[v] = 0;
        dijkstra(graph, { v }, curDist);

        int d = *max_element(curDist.begin(), curDist.end());
        if (bestD > d) {
            bestD = d;
            bestV = v;
        }
    }

    if (test)
        cout << "\n";
    cout << bestV + 1 << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve(i);
}