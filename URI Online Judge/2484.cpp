#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    string s;
    if (!(cin >> s))
        return 0;

    for (int shift = 0; shift < s.size(); shift++) {
        cout << string(shift, ' ');
        for (int i = 0; i + shift < s.size(); i++)
            cout << s[i] << (i + shift + 1 < s.size() ? " " : "\n");
    }

    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}