#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int villageCount, castleCount, edgeCount, distLimit, bootLimit;
    cin >> villageCount >> castleCount >> edgeCount >> distLimit >> bootLimit;

    vector<vector<int>> dist(villageCount + castleCount, vector<int>(villageCount + castleCount, 1e9));

    for (int v = 0; v < villageCount + castleCount; v++)
        dist[v][v] = 0;

    for (int i = 0; i < edgeCount; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        a--;
        b--;
        dist[a][b] = dist[b][a] = min(dist[a][b], w);
    }

    for (int v = 0; v < villageCount; v++)
        for (int a = 0; a < villageCount + castleCount; a++)
            for (int b = 0; b < villageCount + castleCount; b++)
                dist[a][b] = min(dist[a][b], dist[a][v] + dist[v][b]);

    vector<vector<int>> visited(villageCount + castleCount, vector<int>(bootLimit + 1));
    vector<vector<int>> resDist(villageCount + castleCount, vector<int>(bootLimit + 1, 1e9));
    resDist[villageCount + castleCount - 1][bootLimit] = 0;

    while (1) {
        int cv = -1, cb = -1;
        for (int v = 0; v < villageCount + castleCount; v++) {
            for (int b = 0; b <= bootLimit; b++) {
                if (!visited[v][b] && (cv == -1 || resDist[cv][cb] > resDist[v][b])) {
                    cv = v;
                    cb = b;
                }
            }
        }

        if (cv == -1)
            break;
        visited[cv][cb] = 1;

        for (int tv = 0; tv < villageCount + castleCount; tv++) {
            int tb = cb;
            resDist[tv][tb] = min(resDist[tv][tb], resDist[cv][cb] + dist[cv][tv]);

            if (!cb || dist[cv][tv] > distLimit)
                continue;

            tb = cb - 1;
            resDist[tv][tb] = min(resDist[tv][tb], resDist[cv][cb]);
        }
    }

    cout << *min_element(resDist[0].begin(), resDist[0].end()) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++)
        solve();
}