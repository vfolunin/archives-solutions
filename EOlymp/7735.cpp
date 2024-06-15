#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int shift;
    string s;
    if (!(cin >> shift >> s))
        return 0;

    reverse(s.begin(), s.end());

    string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ_.";
    for (char &c : s)
        c = letters[(letters.find(c) + shift) % letters.size()];

    cout << s << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}