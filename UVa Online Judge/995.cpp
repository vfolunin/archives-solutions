#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool divisible(int base, string &num, int den) {
    int mod = 0;
    for (char d : num)
        mod = (mod * base + d - '0') % den;
    return !mod;
}

void rec(int base, vector<bool> &canUse, string &cur, string &res) {
    if (res.size() < cur.size() || res.size() == cur.size() && res < cur)
        res = cur;
    for (int d = cur.empty(); d < base; d++) {
        if (!canUse[d])
            continue;
        cur.push_back(d + '0');
        if (divisible(base, cur, cur.size()))
            rec(base, canUse, cur, res);
        cur.pop_back();
    }
}

bool solve() {
    int base;
    string digits;
    if (!(cin >> base >> digits))
        return 0;

    vector<bool> canUse(10);
    for (char d : digits)
        canUse[d - '0'] = 1;

    string cur, res;
    rec(base, canUse, cur, res);

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}