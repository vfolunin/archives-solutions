#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

int bfs(vector<set<int>> &graph, vector<int> &start, vector<int> &finish) {
    vector<int> dist(graph.size(), 1e9);
    queue<int> q;

    for (int v : start) {
        dist[v] = 0;
        q.push(v);
    }

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int to : graph[v]) {
            if (dist[to] > dist[v] + 1) {
                dist[to] = dist[v] + 1;
                q.push(to);
            }
        }
    }

    int res = 1e9;
    for (int v : finish)
        res = min(res, dist[v]);
    return res != 1e9 ? res : -1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
    int stationCount, lineCount;
    cin >> stationCount >> lineCount;

    vector<vector<int>> linesOf(stationCount);
    for (int line = 0; line < lineCount; line++) {
        int lineSize;
        cin >> lineSize;
        for (int i = 0; i < lineSize; i++) {
            int station;
            cin >> station;
            linesOf[station - 1].push_back(line);
        }
    }

    vector<set<int>> graph(lineCount);
    for (int station = 0; station < stationCount; station++) {
        for (int i = 0; i < linesOf[station].size(); i++) {
            for (int j = i + 1; j < linesOf[station].size(); j++) {
                graph[linesOf[station][i]].insert(linesOf[station][j]);
                graph[linesOf[station][j]].insert(linesOf[station][i]);
            }
        }
    }

    int startStation, finishStation;
    cin >> startStation >> finishStation;

    cout << bfs(graph, linesOf[startStation - 1], linesOf[finishStation - 1]);
}