#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<string> read() {
    vector<string> v;
    while (1) {
        string s;
        if (!(cin >> s))
            return {"#"};
        if (s == "#")
            break;
        v.push_back(s);
    }
    return v;
}

bool solve() {
    vector<string> a = read(), b = read();
    if (a[0] == "#")
        return 0;

    vector<vector<int>> lcs(a.size() + 1, vector<int>(b.size() + 1));
    vector<vector<pair<int, int>>> prev(a.size() + 1, vector<pair<int, int>>(b.size() + 1));

    for (int i = 1; i <= a.size(); i++) {
        for (int j = 1; j <= b.size(); j++) {
            if (a[i - 1] == b[j - 1]) {
                lcs[i][j] = lcs[i - 1][j - 1] + 1;
                prev[i][j] = { i - 1, j - 1 };
            } else if (lcs[i - 1][j] > lcs[i][j - 1]) {
                lcs[i][j] = lcs[i - 1][j];
                prev[i][j] = { i - 1, j };
            } else {
                lcs[i][j] = lcs[i][j - 1];
                prev[i][j] = { i, j  - 1};
            }
        }
    }

    vector<string> path;
    for (int i = a.size(), j = b.size(); i && j; ) {
        auto [pi, pj] = prev[i][j];
        if (pi != i && pj != j)
            path.push_back(a[i - 1]);
        i = pi;
        j = pj;
    }
    reverse(path.begin(), path.end());

    for (int i = 0; i < path.size(); i++)
        cout << path[i] << (i + 1 < path.size() ? ' ' : '\n');
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}