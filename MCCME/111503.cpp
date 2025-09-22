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

    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    vector<vector<int>> reachable(vertexCount, vector<int>(vertexCount, 1));
    for (int i = 0; i < edgeCount; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        reachable[a][b] = reachable[b][a] = 0;
    }

    for (int v = 0; v < vertexCount; v++)
        for (int a = 0; a < vertexCount; a++)
            for (int b = 0; b < vertexCount; b++)
                reachable[a][b] |= reachable[a][v] && reachable[v][b];

    int res, resReachableCount = -1;
    for (int v = 0; v < vertexCount; v++) {
        int reachableCount = 0;
        for (int to = 0; to < vertexCount; to++)
            reachableCount += reachable[v][to];

        if (resReachableCount < reachableCount) {
            res = v;
            resReachableCount = reachableCount;
        }
    }

    cout << res + 1;
}