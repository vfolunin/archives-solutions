#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int vertexCount, edgeCount, minDist;
    cin >> vertexCount >> edgeCount >> minDist;

    if (!vertexCount)
        return 0;

    vector<vector<int>> graph(vertexCount);
    for (int i = 0; i < edgeCount; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }

    vector<vector<int>> can(vertexCount, vector<int>(21));
    can[0][1] = 1;

    for (int dist = 0; dist < 20; dist++)
        for (int v = 0; v < vertexCount; v++)
            if (can[v][dist])
                for (int to : graph[v])
                    can[to][dist + 1] = 1;
    
    int res = find(can[vertexCount - 1].begin() + minDist, can[vertexCount - 1].end(), 1) - can[vertexCount - 1].begin();
    if (res == 21)
        cout << "LOSER\n";
    else
        cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}