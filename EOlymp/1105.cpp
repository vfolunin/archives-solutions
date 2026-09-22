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
    vertexCount++;

    vector<vector<int>> weight(vertexCount, vector<int>(vertexCount));
    for (int a = 0; a < vertexCount; a++)
        for (int b = 0; b < vertexCount; b++)
            cin >> weight[a][b];

    for (int v = 0; v < vertexCount; v++)
        for (int a = 0; a < vertexCount; a++)
            for (int b = 0; b < vertexCount; b++)
                weight[a][b] = min(weight[a][b], weight[a][v] + weight[v][b]);

    vector<vector<int>> dist(1 << vertexCount, vector<int>(vertexCount, 1e9));
    dist[1][0] = 0;
    
    for (int mask = 2; mask < (1 << vertexCount); mask++) {
        for (int last = 0; last < vertexCount; last++) {
            if (!(mask & (1 << last)))
                continue;
            
            for (int prev = 0; prev < vertexCount; prev++) {
                if (prev == last || !(mask & (1 << prev)))
                    continue;

                dist[mask][last] = min(dist[mask][last], dist[mask ^ (1 << last)][prev] + weight[prev][last]);
            }
        }
    }

    int res = 1e9;
    for (int last = 1; last < vertexCount; last++)
        res = min(res, dist[(1 << vertexCount) - 1][last] + weight[last][0]);

    cout << res;
}