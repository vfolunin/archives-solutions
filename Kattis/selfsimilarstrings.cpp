#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int getCount(const string &s, const string &part) {
    int count = 0;
    for (int i = 0; i + part.size() <= s.size(); i++)
        count += s.substr(i, part.size()) == part;
    return count;
}

bool check(const string &s, int len) {
    for (int i = 0; i + len <= s.size(); i++)
        if (getCount(s, s.substr(i, len)) == 1)
            return 0;
    return 1;
}

bool solve() {
    string s;
    if (!(cin >> s))
        return 0;

    int res = s.size() - 1;
    while (res && !check(s, res))
        res--;

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}