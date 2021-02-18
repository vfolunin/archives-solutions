#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int h, w;
    cin >> h >> w;
    
    if (!h && !w)
        return 0;

    vector<string> a(h);
    for (string &row : a)
        cin >> row;

    static int di[] = { -1, -1, -1, 0, 1, 1, 1, 0 };
    static int dj[] = { -1, 0, 1, 1, 1, 0, -1, -1 };

    int res = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (a[i][j] != '*')
                continue;

            int k = 0;
            for (int d = 0; d < 8; d++) {
                int ti = i + di[d], tj = j + dj[d];
                k += (0 <= ti && ti < h && 0 <= tj && tj < w && a[ti][tj] == '*');
            }
            res += !k;
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