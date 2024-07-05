#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int vertexCount;
    cin >> vertexCount;

    if (!vertexCount)
        return 0;

    vector<vector<int>> dist(vertexCount, vector<int>(vertexCount, 1e9));

    while (1) {
        int v;
        cin >> v;
        if (!v)
            break;

        while (1) {
            int to;
            cin >> to;
            if (!to)
                break;
            dist[v - 1][to - 1] = 0;
        }
    }

    for (int v = 0; v < vertexCount; v++)
        for (int a = 0; a < vertexCount; a++)
            for (int b = 0; b < vertexCount; b++)
                dist[a][b] = min(dist[a][b], dist[a][v] + dist[v][b]);

    int queryCount;
    cin >> queryCount;

    for (int i = 0; i < queryCount; i++) {
        int v;
        cin >> v;
        v--;

        vector<int> reachable;
        for (int to = 0; to < vertexCount; to++)
            if (dist[v][to])
                reachable.push_back(to);

        cout << reachable.size();
        for (int to : reachable)
            cout << " " << to + 1;
        cout << "\n";
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}