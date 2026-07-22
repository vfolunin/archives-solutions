#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int find(string &pattern, string &text) {
    string s = pattern + "$" + text;
    vector<int> p(s.size());
    for (int i = 1; i < s.size(); i++) {
        int border = p[i - 1];
        while (border > 0 && s[i] != s[border])
            border = p[border - 1];
        p[i] = border + (s[i] == s[border]);
    }
    return p.back();
}

bool solve() {
    string s;
    if (!(cin >> s))
        return 0;

    string r = s;
    reverse(r.begin(), r.end());
    int n = s.size() - find(r, s);

    cout << s << r.substr(r.size() - n, n) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}