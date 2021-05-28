#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    if (!vertexCount)
        return 0;

    vector<vector<int>> graph(vertexCount);
    for (int i = 0; i < edgeCount; i++) {
        int a, b;
        cin >> a >> b;

        graph[a - 1].push_back(b - 1);
        graph[b - 1].push_back(a - 1);
    }

    int start, finish, dist;
    cin >> start >> finish >> dist;
    start--;
    finish--;

    vector<vector<int>> can(2, vector<int>(vertexCount));
    can[0][start] = 1;

    for (int i = 1; i <= dist; i++) {
        fill(can[1].begin(), can[1].end(), 0);

        for (int v = 0; v < vertexCount; v++) {
            if (!can[0][v])
                continue;
            for (int to : graph[v])
                can[1][to] = 1;
        }

        can[0] = can[1];
    }

    if (can[0][finish])
        cout << "Yes, Teobaldo can travel.\n";
    else
        cout << "No, Teobaldo can not travel.\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}