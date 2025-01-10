#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

bool solve() {
    string s;
    getline(cin, s);

    if (s == "#")
        return 0;

    unordered_map<char, string> escapes;
    escapes[' '] = "%20";
    escapes['!'] = "%21";
    escapes['$'] = "%24";
    escapes['%'] = "%25";
    escapes['('] = "%28";
    escapes[')'] = "%29";
    escapes['*'] = "%2a";

    for (char c : s) {
        if (escapes.count(c))
            cout << escapes[c];
        else
            cout << c;
    }
    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}