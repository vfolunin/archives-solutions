#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool fill(string &s, int h, int w) {
    vector<string> a(h, string(w, ' '));

    static int dy[] = { -1, 0, 1, 0 };
    static int dx[] = { 0, 1, 0, -1 };
    int d = 0, y = 0, x = 0;

    for (int i = 0; 1; i++) {
        a[y][x] = s[i];
        if (i + 1 == s.size())
            break;
        while (1) {
            int ty = y + dy[d];
            int tx = x + dx[d];
            if (0 <= ty && ty < h && 0 <= tx && tx < w && a[ty][tx] == ' ') {
                y = ty;
                x = tx;
                break;
            }
            d = (d + 1) % 4;
        }
    }

    for (int y = 1; y < h; y++)
        if (a[y] != a[0])
            return 0;
    return 1;
}

void solve(int test) {
    string s;
    cin >> s;

    int res = 1e9;
    for (int h = 2; h < s.size(); h++)
        if (s.size() % h == 0 && fill(s, h, s.size() / h))
            res = min<int>(res, h + s.size() / h);

    if (res == 1e9)
        res = -1;

    cout << "Case " << test << ": " << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}