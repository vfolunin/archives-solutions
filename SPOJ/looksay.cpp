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

    vector<pair<int, char>> parts;
    for (char c : s) {
        if (parts.empty() || parts.back().second != c)
            parts.push_back({ 1, c });
        else
            parts.back().first++;
    }

    for (auto &[count, c] : parts)
        cout << to_string(count) << c;
    cout << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}