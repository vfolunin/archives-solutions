#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void rec(int count, int prevV, int curMask, int curTime, vector<vector<int>> &dist, vector<int> &time) {
    if (count > 4)
        return;

    int vertexCount = dist.size();

    for (int v = 1; v < vertexCount - 1; v++) {
        int nextMask = curMask | (1 << (v - 1));

        int nextTime = curTime;
        if (prevV != v)
            nextTime += 5;
        nextTime += dist[prevV][v];

        time[nextMask] = min(time[nextMask], nextTime + dist[v][vertexCount - 1]);

        rec(count + 1, v, nextMask, nextTime, dist, time);
    }
}

int rec2(int carCount, int mask, vector<vector<int>> &time) {
    int &res = time[carCount][mask];
    if (!carCount || res != 1.1e9)
        return res;

    res = 1e9;
    for (int submask = mask; submask; submask = (submask - 1) & mask)
        res = min(res, max(rec2(1, submask, time), rec2(carCount - 1, mask ^ submask, time)));
    return res;
}

bool solve() {
    int friendCount, edgeCount;
    if (!(cin >> friendCount >> edgeCount))
        return 0;

    int vertexCount = friendCount + 2;
    vector<vector<int>> dist(vertexCount, vector<int>(vertexCount, 1e9));

    for (int v = 0; v < vertexCount; v++)
        dist[v][v] = 0;

    for (int i = 0; i < edgeCount; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        dist[a][b] = dist[b][a] = min(dist[a][b], w);
    }

    for (int v = 0; v < vertexCount; v++)
        for (int a = 0; a < vertexCount; a++)
            for (int b = 0; b < vertexCount; b++)
                dist[a][b] = min(dist[a][b], dist[a][v] + dist[v][b]);

    int carCount = (friendCount + 4) / 5;
    vector<vector<int>> time(carCount + 1, vector<int>(1 << friendCount, 1.1e9));
    rec(0, 0, 0, 0, dist, time[1]);
    time[1][0] = dist[0][vertexCount - 1];

    int res = rec2(carCount, (1 << friendCount) - 1, time);

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}