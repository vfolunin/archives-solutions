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

    long long l = 0, r = count(s.begin(), s.end(), 's'), res = 0;
    for (char c : s) {
        r -= c == 's';
        if (c == 'm')
            res += l * r;
        l += c == 's';
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