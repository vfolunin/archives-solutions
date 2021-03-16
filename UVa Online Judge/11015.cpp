#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    if (!vertexCount)
        return 0;

    vector<string> vertexName(vertexCount);
    for (string &name : vertexName)
        cin >> name;

    vector<vector<int>> dist(vertexCount, vector<int>(vertexCount, 1e9));
    for (int v = 0; v < vertexCount; v++)
        dist[v][v] = 0;
    for (int i = 0; i < edgeCount; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        dist[a - 1][b - 1] = dist[b - 1][a - 1] = w;
    }

    for (int v = 0; v < vertexCount; v++)
        for (int a = 0; a < vertexCount; a++)
            for (int b = 0; b < vertexCount; b++)
                dist[a][b] = min(dist[a][b], dist[a][v] + dist[v][b]);

    int res = -1, resSum = 0;
    for (int v = 0; v < vertexCount; v++) {
        int curSum = 0;
        for (int to = 0; to < vertexCount; to++)
            curSum += dist[v][to];
        if (res == -1 || curSum < resSum) {
            resSum = curSum;
            res = v;
        }
    }

    cout << "Case #" << test << " : " << vertexName[res] << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}