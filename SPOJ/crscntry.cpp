#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> read() {
    vector<int> res;
    for (int value; cin >> value && value; )
        res.push_back(value);
    return res;
}

int getLcsSize(vector<int> &a, vector<int> &b) {
    vector<vector<int>> lcs(a.size() + 1, vector<int>(b.size() + 1));
    for (int ai = 1; ai <= a.size(); ai++) {
        for (int bi = 1; bi <= b.size(); bi++) {
            if (a[ai - 1] == b[bi - 1])
                lcs[ai][bi] = lcs[ai - 1][bi - 1] + 1;
            else
                lcs[ai][bi] = max(lcs[ai - 1][bi], lcs[ai][bi - 1]);
        }
    }
    return lcs[a.size()][b.size()];
}

void solve() {
    vector<int> a = read();
    
    int res = 0;
    while (1) {
        vector<int> b = read();
        if (b.empty())
            break;
        res = max(res, getLcsSize(a, b));
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