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

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string text, pattern;
    cin >> text >> pattern;

    vector<int> p = prefixFunction(pattern + " " + text);

    vector<int> res;
    for (int i = 0; i < p.size(); i++)
        if (p[i] == pattern.size())
            res.push_back(i - 2 * pattern.size());

    cout << res.size() << "\n";
    for (int value : res)
        cout << value + 1 << " ";
}