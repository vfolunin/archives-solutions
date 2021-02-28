#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int dfs(vector<string> &a, int y, int x, char c) {
    a[y][x] = '.';
    int res = 1;

    static int dy[] = { -1, 0, 1, 0 };
    static int dx[] = { 0, 1, 0, -1 };

    for (int d = 0; d < 4; d++) {
        int ty = y + dy[d], tx = x + dx[d];
        if (0 <= ty && ty < a.size() && 0 <= tx && tx < a[0].size() && a[ty][tx] == c)
            res += dfs(a, ty, tx, c);
    }

    return res;
}

bool compare(pair<char, int> &a, pair<char, int> &b) {
    if (a.second != b.second)
        return a.second > b.second;
    return a.first < b.first;
}

bool solve(int test) {
    int h, w;
    cin >> h >> w;

    if (!h && !w)
        return 0;

    vector<string> a(h);
    for (string &row : a)
        cin >> row;

    vector<pair<char, int>> res;
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            if (a[y][x] != '.') {
                char c = a[y][x];
                res.emplace_back(c, dfs(a, y, x, c));
            }
        }
    }

    sort(res.begin(), res.end(), compare);

    cout << "Problem " << test << ":\n";
    for (auto &[c, k] : res)
        cout << c << " " << k << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}