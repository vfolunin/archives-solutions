#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    string s;
    cin >> s;

    vector<pair<char, int>> v;
    for (char c : s) {
        if (isalpha(c))
            v.push_back({ c, 0 });
        else
            v.back().second = v.back().second * 10 + c - '0';
    }
    for (auto &[c, k] : v)
        k = max(k, 1);

    static map<char, double> weight = { {'C', 12.01}, {'H', 1.008}, {'N', 14.01}, {'O', 16.00} };
    double mass = 0;
    for (auto &[c, k] : v)
        mass += weight[c] * k;

    cout.precision(3);
    cout << fixed << mass << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}