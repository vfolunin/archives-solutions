#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool can(long long la, long long lb, long long k) {
    if (la == lb)
        return k % 2 == 0;
    return k * lb % (la + lb) == 0 && k * lb / (la + lb) >= 0;
}

void solve() {
    int size, le, lw, ln, ls;
    string s;
    cin >> size >> le >> lw >> ln >> ls >> s;

    int ke = 0, kw = 0, kn = 0, ks = 0;
    for (char c : s) {
        ke += c == 'E';
        kw += c == 'W';
        kn += c == 'N';
        ks += c == 'S';
    }

    cout << (can(le, lw, ke + kw) && can(ln, ls, kn + ks) ? "Yes\n" : "No\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    for (int i = 0; i < size; i++)
        solve();
}