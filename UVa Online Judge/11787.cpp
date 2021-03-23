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

    static string symbols = "BUSPFTM";
    static vector<int> values = { 1, 10, 100, 1000, 10000, 100000, 1000000 };

    for (char &c : s)
        c = symbols.find(c);

    if (!is_sorted(s.begin(), s.end()) && !is_sorted(s.rbegin(), s.rend())) {
        cout << "error\n";
        return;
    }

    for (int i = 0; i < symbols.size(); i++) {
        if (count(s.begin(), s.end(), i) > 9) {
            cout << "error\n";
            return;
        }
    }

    int res = 0;
    for (char c : s)
        res += values[c];

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