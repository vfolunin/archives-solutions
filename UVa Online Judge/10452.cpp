#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

string rec(vector<string> &a, int i, int y, int x) {
    static string s = "IEHOVA#";
    if (i == s.size())
        return "";
    
    static int dy[] = { 0, 0, -1 };
    static int dx[] = { -1, 1, 0 };
    static string ds[] = { " left", " right", " forth" };

    for (int d = 0; d < 3; d++) {
        int ty = y + dy[d], tx = x + dx[d];
        if (0 <= ty && ty <= a.size() && 0 <= tx && tx <= a[0].size() && a[ty][tx] == s[i]) {
            string r = rec(a, i + 1, ty, tx);
            if (r != "-")
                return ds[d] + r;
        }
    }
    
    return "-";
}

void solve() {
    int h, w;
    cin >> h >> w;

    vector<string> a(h);
    int sy, sx;

    for (int y = 0; y < h; y++) {
        cin >> a[y];
        int x = a[y].find('@');
        if (x != -1) {
            sy = y;
            sx = x;
        }
    }

    cout << rec(a, 0, sy, sx).substr(1) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}