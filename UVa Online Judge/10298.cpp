#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    string s;
    cin >> s;

    if (s == ".")
        return 0;

    vector<int> p(s.size());
    for (int i = 1; i < s.size(); i++) {
        int border = p[i - 1];
        while (border && s[border] != s[i])
            border = p[border - 1];
        p[i] = border + (s[border] == s[i]);
    }

    int period = s.size() - p.back();
    if (s.size() % period)
        period = 1;

    cout << s.size() / period << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}