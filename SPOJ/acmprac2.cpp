#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int count;
    string s;
    cin >> count >> s;

    vector<int> parts = { 1 };
    for (int i = 1; i < s.size(); i++) {
        if (s[i - 1] == s[i])
            parts.back()++;
        else
            parts.push_back(1);
    }

    sort(parts.rbegin(), parts.rend());

    int res = 0;
    for (int i = 0; i < count; i++)
        res += parts[i];

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