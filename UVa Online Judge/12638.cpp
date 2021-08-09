#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool read(string &s, int &i) {
    if (i >= s.size())
        return 0;

    if (s[i++] != '1')
        return 1;

    return read(s, i) && read(s, i);
}

bool solve() {
    string s;
    if (!(cin >> s))
        return 0;

    int res = 0, i = 0;
    while (i < s.size()) {
        if (!read(s, i)) {
            res = 0;
            break;
        }
        res++;
    }

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}