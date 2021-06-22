#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Edge {
    int a, b, w;
};

void solve(int test) {
    int vertexCount;
    cin >> vertexCount;

    map<string, int> vertexId;
    for (int i = 0; i < vertexCount; i++) {
        string name;
        cin >> name;
        vertexId[name] = vertexId.size();
    }

    int edgeCount;
    cin >> edgeCount;

    vector<Edge> edges(edgeCount);
    for (auto &[a, b, w] : edges) {
        string aName, bName;
        cin >> aName >> bName >> w;
        a = vertexId[aName];
        b = vertexId[bName];
    }

    vector<vector<int>> dist(vertexCount, vector<int>(vertexCount, 1e9));
    dist[0][0] = 0;

    for (auto &[a, b, w] : edges)
        if (!a)
            dist[0][b] = min(dist[0][b], w);

    for (int stopCount = 0; stopCount + 1 < vertexCount; stopCount++) {
        for (int v = 0; v < vertexCount; v++)
            dist[stopCount + 1][v] = min(dist[stopCount + 1][v], dist[stopCount][v]);
        for (auto &[a, b, w] : edges)
            dist[stopCount + 1][b] = min(dist[stopCount + 1][b], dist[stopCount][a] + w);
    }

    int queryCount;
    cin >> queryCount;

    if (test > 1)
        cout << "\n";
    cout << "Scenario #" << test << "\n";
    for (int i = 0; i < queryCount; i++) {
        int stopCount;
        cin >> stopCount;

        int res = dist[min(stopCount, vertexCount - 1)][vertexCount - 1];

        if (res != 1e9)
            cout << "Total cost of flight(s) is $" << res << "\n";
        else
            cout << "No satisfactory flights\n";
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}