#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

int bfs(vector<vector<int>> &to, int a, int b, int c) {
    vector<vector<int>> dist(to.size(), vector<int>(to.size(), 1e9));
    queue<int> q;

    dist[a][b] = 0;
    q.push(a);
    q.push(b);

    while (!q.empty()) {
        int a = q.front();
        q.pop();
        int b = q.front();
        q.pop();

        int ta = to[a][b], tb = to[b][a];
        if (ta != -1 && dist[ta][b] == 1e9) {
            dist[ta][b] = dist[a][b] + 1;
            q.push(ta);
            q.push(b);
        }
        if (tb != -1 && dist[a][tb] == 1e9) {
            dist[a][tb] = dist[a][b] + 1;
            q.push(a);
            q.push(tb);
        }
    }

    int res = 1e9;
    for (int v = 0; v < dist.size(); v++)
        res = min(res, min(dist[v][c], dist[c][v]));
    return res;
}

bool solve(int test) {
    int vertexCount;
    cin >> vertexCount;

    if (!vertexCount)
        return 0;

    vector<vector<int>> to(vertexCount, vector<int>(vertexCount));
    for (int i = 0; i < vertexCount; i++) {
        for (int j = 0; j < vertexCount; j++) {
            cin >> to[i][j];
            to[i][j]--;
        }
    }

    int a, b, c;
    cin >> a >> b >> c;
    int res = bfs(to, a - 1, b - 1, c - 1);

    cout << "Game #" << test << "\n";
    if (res == 1e9)
        cout << "Destination is Not Reachable !\n\n";
    else
        cout << "Minimum Number of Moves = " << res << "\n\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}