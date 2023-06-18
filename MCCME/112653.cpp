#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount;
    cin >> vertexCount;

    vector<vector<int>> dist(vertexCount, vector<int>(vertexCount, 1e9));
    for (int a = 0; a < vertexCount; a++) {
        for (int b = 0; b < vertexCount; b++) {
            cin >> dist[a][b];
            if (!dist[a][b] && a != b)
                dist[a][b] = 1e4;
        }
    }

    for (int v = 0; v < vertexCount; v++)
        for (int a = 0; a < vertexCount; a++)
            for (int b = 0; b < vertexCount; b++)
                dist[a][b] = min(dist[a][b], dist[a][v] + dist[v][b]);

    vector<int> studentCount(vertexCount);
    for (int &count : studentCount)
        cin >> count;

    int res, resCost = 1e9;
    for (int v = 0; v < vertexCount; v++) {
        int cost = 0;
        for (int from = 0; from < vertexCount; from++)
            cost += studentCount[from] * dist[from][v];

        if (resCost > cost) {
            res = v;
            resCost = cost;
        }
    }

    cout << res + 1 << " " << resCost;
}