#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int prefixFunction(const string &s, int limit) {
    int res = 0;
    vector<int> p(s.size());

    for (int i = 1; i < s.size(); i++) {
        int border = p[i - 1];
        while (border > 0 && s[i] != s[border])
            border = p[border - 1];
        p[i] = border + (s[i] == s[border]);

        if (p[i] == limit) {
            p[i] = 0;
            res++;
        }
    }

    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string text, pattern;
    cin >> text >> pattern;

    cout << prefixFunction(pattern + "#" + text, pattern.size());
}