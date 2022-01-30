#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int dfs(vector<string> &a, int i, int j) {
    int res = a[i][j] == 'G';
    a[i][j] = '#';

    static int di[] = { -1, 0, 1, 0 };
    static int dj[] = { 0, 1, 0, -1 };

    int trapCount = 0;
    for (int d = 0; d < 4; d++) {
        int ti = i + di[d];
        int tj = j + dj[d];
        if (0 <= ti && ti < a.size() && 0 <= tj && tj < a[0].size() && a[ti][tj] == 'T')
            trapCount++;
    }

    if (!trapCount) {
        for (int d = 0; d < 4; d++) {
            int ti = i + di[d];
            int tj = j + dj[d];
            if (0 <= ti && ti < a.size() && 0 <= tj && tj < a[0].size() && a[ti][tj] != '#')
                res += dfs(a, ti, tj);
        }
    }

    return res;
}

bool solve() {
    int h, w;
    if (!(cin >> w >> h))
        return 0;

    vector<string> a(h);
    int si, sj;

    for (int i = 0; i < h; i++) {
        cin >> a[i];
        if (int j = a[i].find('P'); j != -1) {
            si = i;
            sj = j;
        }
    }

    cout << dfs(a, si, sj) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}