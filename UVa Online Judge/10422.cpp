#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

map<vector<string>, int> bfs() {
    map<vector<string>, int> dist;
    queue<vector<string>> q;

    vector<string> start = {
        "11111",
        "01111",
        "00 11",
        "00001",
        "00000"
    };

    dist[start] = 0;
    q.push(start);

    while (!q.empty()) {
        vector<string> a = q.front();
        q.pop();
        int curDist = dist[a];
        if (curDist == 10)
            continue;

        int si, sj;
        for (int i = 0; i < 5; i++) {
            if (int j = a[i].find(' '); j != -1) {
                si = i;
                sj = j;
            }
        }

        static int di[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
        static int dj[] = { 1, 2, 2, 1, -1, -2, -2, -1 };
        for (int d = 0; d < 8; d++) {
            int ti = si + di[d];
            int tj = sj + dj[d];
            if (ti < 0 || ti > 4 || tj < 0 || tj > 4)
                continue;
            swap(a[si][sj], a[ti][tj]);
            if (!dist.count(a)) {
                dist[a] = curDist + 1;
                q.push(a);
            }
            swap(a[si][sj], a[ti][tj]);
        }
    }

    return dist;
}

void solve() {
    vector<string> a(5);
    for (string &row : a)
        getline(cin, row);

    static map<vector<string>, int> dist = bfs();

    if (!dist.count(a))
        cout << "Unsolvable in less than 11 move(s).\n";
    else
        cout << "Solvable in " << dist[a] << " move(s).\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++)
        solve();
}