#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int solve(string s) {
    int res = 0;
    for (int i = 0; i + 1 < s.size(); i++) {
        if (s[i] == '1') {
            res++;
            s[i] ^= 1;
            s[i + 1] ^= 1;
            if (i + 2 < s.size())
                s[i + 2] ^= 1;
        }
    }
    return s.back() == '0' ? res : 1e9;
}

void solve() {
    string s;
    cin >> s;

    int res = min(solve(s), solve('1' + s));

    cout << (res != 1e9 ? res : -1) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}