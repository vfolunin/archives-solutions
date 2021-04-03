#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int dfs(vector<string> &a, int y, int x) {
    a[y][x] = '0';
    int res = 1;

    static int dy[] = { -1, -1, -1, 0, 1, 1, 1, 0 };
    static int dx[] = { -1, 0, 1, 1, 1, 0, -1, -1 };

    for (int d = 0; d < 8; d++) {
        int ty = y + dy[d];
        int tx = x + dx[d];
        if (0 <= ty && ty < a.size() && 0 <= tx && tx < a[0].size() && a[ty][tx] == '1')
            res += dfs(a, ty, tx);
    }

    return res;
}

void solve(int test) {
    vector<string> a;
    while (1) {
        string line;
        if (!getline(cin, line) || line.empty())
            break;
        a.push_back(line);
    }

    int res = 0;
    for (int y = 0; y < a.size(); y++)
        for (int x = 0; x < a[0].size(); x++)
            if (a[y][x] == '1')
                res = max(res, dfs(a, y, x));

    if (test)
        cout << "\n";
    cout << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    cin.ignore(2);

    for (int i = 0; i < n; i++)
        solve(i);
}