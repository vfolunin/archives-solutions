#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
using namespace std;

bool solve() {
    string pos1, pos2;
    if (!(cin >> pos1 >> pos2))
        return 0;

    vector<vector<int>> dist(8, vector<int>(8, -1));
    queue<int> q;
    vector<int> di = { -2, -2, -1, 1, 2, 2, 1, -1 };
    vector<int> dj = { -1, 1, 2, 2, 1, -1, -2, -2 };

    dist[pos1[1] - '1'][pos1[0] - 'a'] = 0;
    q.push(pos1[1] - '1');
    q.push(pos1[0] - 'a');

    while (!q.empty()) {
        int i = q.front();
        q.pop();
        int j = q.front();
        q.pop();

        for (int d = 0; d < 8; d++) {
            int ti = i + di[d], tj = j + dj[d];
            if (ti < 0 || ti > 7 || tj < 0 || tj > 7 || dist[ti][tj] != -1)
                continue;
            dist[ti][tj] = dist[i][j] + 1;
            q.push(ti);
            q.push(tj);
        }
    }

    cout << "To get from " << pos1 << " to " << pos2 << " takes ";
    cout << dist[pos2[1] - '1'][pos2[0] - 'a'] << " knight moves.\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}