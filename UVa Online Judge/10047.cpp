#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

int bfs(vector<string> &a, int si, int sj, int ti, int tj) {
    vector<vector<vector<vector<int>>>> dist(a.size(), vector<vector<vector<int>>>(a[0].size(), vector<vector<int>>(4, vector<int>(5, -1))));
    queue<int> q;

    dist[si][sj][0][0] = 0;
    q.push(si);
    q.push(sj);
    q.push(0);
    q.push(0);

    while (!q.empty()) {
        int i = q.front();
        q.pop();
        int j = q.front();
        q.pop();
        int d = q.front();
        q.pop();
        int c = q.front();
        q.pop();

        if (dist[i][j][(d + 1) % 4][c] == -1) {
            dist[i][j][(d + 1) % 4][c] = dist[i][j][d][c] + 1;
            q.push(i);
            q.push(j);
            q.push((d + 1) % 4);
            q.push(c);
        }

        if (dist[i][j][(d + 3) % 4][c] == -1) {
            dist[i][j][(d + 3) % 4][c] = dist[i][j][d][c] + 1;
            q.push(i);
            q.push(j);
            q.push((d + 3) % 4);
            q.push(c);
        }

        static vector<int> di = { -1, 0, 1, 0 };
        static vector<int> dj = { 0, 1, 0, -1 };
        int ti = i + di[d], tj = j + dj[d];

        if (0 <= ti && ti < a.size() && 0 <= tj && tj < a[0].size() && a[ti][tj] != '#' && dist[ti][tj][d][(c + 1) % 5] == -1) {
            dist[ti][tj][d][(c + 1) % 5] = dist[i][j][d][c] + 1;
            q.push(ti);
            q.push(tj);
            q.push(d);
            q.push((c + 1) % 5);
        }
    }

    int res = -1;
    for (int d = 0; d < 4; d++)
        if (dist[ti][tj][d][0] != -1 && (res == -1 || res > dist[ti][tj][d][0]))
            res = dist[ti][tj][d][0];
    return res;
}

bool solve(int test) {
    int h, w;
    cin >> h >> w;

    if (!h && !w)
        return 0;

    vector<string> a(h);
    int si, sj, ti, tj;
    for (int i = 0; i < h; i++) {
        cin >> a[i];
        if (int j = a[i].find('S'); j != -1) {
            si = i;
            sj = j;
        }
        if (int j = a[i].find('T'); j != -1) {
            ti = i;
            tj = j;
        }
    }

    int res = bfs(a, si, sj, ti, tj);

    if (test > 1)
        cout << "\n";
    cout << "Case #" << test << "\n";
    if (res == -1)
        cout << "destination not reachable\n";
    else
        cout << "minimum time = " << res << " sec\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}