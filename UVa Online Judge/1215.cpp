#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool has(vector<int> &pos, int l, int r) {
    auto p = lower_bound(pos.begin(), pos.end(), l);
    auto q = lower_bound(pos.begin(), pos.end(), r);
    return p != q;
}

int cost(vector<vector<int>> &pos, int l, int m, int r) {
    int res = 0;
    for (vector<int> &row : pos) {
        bool aHas = has(row, l, m);
        bool bHas = has(row, m, r);
        res += aHas ^ bHas;
    }
    return res;
}

void solve() {
    int cutCount;
    cin >> cutCount;

    vector<int> cuts(cutCount);
    for (int &cut : cuts)
        cin >> cut;

    string s;
    cin >> s;

    vector<vector<int>> pos(26);
    for (int i = 0; i < s.size(); i++)
        pos[s[i] - 'a'].push_back(i);

    set<int> actualCuts = { 0, (int)s.size() };
    int res = 0;

    for (int cut : cuts) {
        auto q = actualCuts.upper_bound(cut), p = prev(q);
        res += cost(pos, *p, cut, *q);
        actualCuts.insert(cut);
    }

    cout << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}