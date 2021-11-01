#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool hasRepeatedDigits(int n) {
    string s = to_string(n);
    return set<char>(s.begin(), s.end()).size() < s.size();
}

bool solve() {
    int l, r;
    if (!(cin >> l >> r))
        return 0;

    int res = 0;
    for (int i = l; i <= r; i++)
        res += !hasRepeatedDigits(i);

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}