#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

string toBin(int value) {
    string res;
    for (int i = 0; i < 8; i++) {
        res += '0' + value % 2;
        value /= 2;
    }
    reverse(res.begin(), res.end());
    return res;
}

bool solve() {
    string pattern;
    if (!(cin >> pattern))
        return 0;

    int res = 0;
    for (int i = 0; i < (1 << 8); i++) {
        string s = toBin(i);
        if (s.find(pattern) == -1)
            res += count(s.begin(), s.end(), '1');
    }

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}