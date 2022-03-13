#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> prefixFunction(const string &s) {
    vector<int> p(s.size());
    for (int i = 1; i < s.size(); i++) {
        int border = p[i - 1];
        while (border > 0 && s[i] != s[border])
            border = p[border - 1];
        p[i] = border + (s[i] == s[border]);
    }
    return p;
}

bool solve() {
    string pattern;
    if (!getline(cin, pattern))
        return 0;

    string text;
    getline(cin, text);

    vector<int> p = prefixFunction(pattern + "#" + text);
    for (int l = 0, r = pattern.size() - 1; r < text.size(); l++, r++)
        if (p[pattern.size() + 1 + r] == pattern.size())
            cout << l << " ";

    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}