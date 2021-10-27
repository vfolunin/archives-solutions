#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    string s;
    if (!(cin >> s >> s))
        return 0;

    int d = 0;
    for (char c : s)
        d = (d + (c == 'D' ? 1 : 3)) % 4;

    cout << "NLSO"[d] << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}