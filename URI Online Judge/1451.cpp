#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    string s;
    if (!(cin >> s))
        return 0;

    list<char> l;
    auto pos = l.begin();

    for (char c : s) {
        if (c == '[')
            pos = l.begin();
        else if (c == ']')
            pos = l.end();
        else
            pos = next(l.insert(pos, c));
    }

    for (char c : l)
        cout << c;
    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}