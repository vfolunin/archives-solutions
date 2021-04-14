#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int vertexCount;
    cin >> vertexCount;

    vector<string> vertexName(vertexCount);
    for (string &name : vertexName)
        cin >> name;
    sort(vertexName.begin(), vertexName.end());

    map<string, int> vertexId;
    for (int i = 0; i < vertexCount; i++)
        vertexId[vertexName[i]] = i;

    vector<vector<int>> dist(vertexCount, vector<int>(vertexCount, -1e9));
    for (int v = 0; v < vertexCount; v++)
        dist[v][v] = 0;

    int nonSourceCount;
    cin >> nonSourceCount;

    for (int i = 0; i < nonSourceCount; i++) {
        string name;
        cin >> name;
        int v = vertexId[name];

        int edgeCount;
        cin >> edgeCount;
        for (int j = 0; j < edgeCount; j++) {
            cin >> name;
            int p = vertexId[name];
            dist[p][v] = 1;
        }
    }

    for (int v = 0; v < vertexCount; v++)
        for (int a = 0; a < vertexCount; a++)
            for (int b = 0; b < vertexCount; b++)
                dist[a][b] = max(dist[a][b], dist[a][v] + dist[v][b]);

    vector<vector<int>> prerequisites(vertexCount);
    for (int v = 0; v < vertexCount; v++)
        for (int p = 0; p < vertexCount; p++)
            if (dist[p][v] == 1)
                prerequisites[v].push_back(p);

    for (int v = 0; v < vertexCount; v++) {
        if (!prerequisites[v].empty()) {
            cout << vertexName[v] << " " << prerequisites[v].size();
            for (int p : prerequisites[v])
                cout << " " << vertexName[p];
            cout << "\n";
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}