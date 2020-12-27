#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

void dfs(vector<string> &a, int i, int j) {
    static int di[] = { -1, -1, -1, 0, 1, 1, 1, 0 };
    static int dj[] = { -1, 0, 1, 1, 1, 0, -1, -1 };

    a[i][j] = '*';

    for (int d = 0; d < 8; d++) {
        int ti = i + di[d], tj = j + dj[d];
        if (0 <= ti && ti < a.size() && 0 <= tj && tj < a[0].size() && a[ti][tj] == '@')
            dfs(a, ti, tj);
    }
}

bool solve() {
    int h, w;
    cin >> h >> w;

    if (!h && !w)
        return 0;

    vector<string> a(h);
    for (string &s : a)
        cin >> s;

    int res = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (a[i][j] == '@') {
                res++;
                dfs(a, i, j);
            }
        }
    }
    
    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}