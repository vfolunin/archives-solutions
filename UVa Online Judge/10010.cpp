#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool find(vector<string> &a, int i, int j, const string &s) {
    static const int di[] = { -1, -1, -1, 0, 1, 1, 1, 0 };
    static const int dj[] = { -1, 0, 1, 1, 1, 0, -1, -1 };
    
    for (int d = 0; d < 8; d++) {
        bool ok = 1;
        for (int step = 0; ok && step < s.size(); step++) {
            int ti = i + di[d] * step, tj = j + dj[d] * step;
            ok &= (
                0 <= ti && ti < a.size() &&
                0 <= tj && tj <= a[0].size() &&
                tolower(a[ti][tj]) == tolower(s[step])
            );
        }
        if (ok)
            return 1;
    }

    return 0;
}

pair<int, int> find(vector<string> &a, const string &s) {
    for (int i = 0; i < a.size(); i++)
        for (int j = 0; j < a[0].size(); j++)
            if (find(a, i, j, s))
                return { i, j };
    return { -1, -1 };
}

void solve(int test) {
    int h, w;
    cin >> h >> w;

    vector<string> a(h);
    for (string &row : a)
        cin >> row;

    int n;
    cin >> n;

    if (test)
        cout << "\n";

    for (int i = 0; i < n; i++) {
        string word;
        cin >> word;
        auto [y, x] = find(a, word);
        cout << y + 1 << " " << x + 1 << "\n";
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve(i);
}