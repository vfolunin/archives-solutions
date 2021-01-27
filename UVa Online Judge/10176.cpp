#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int n = 0, mod = 131071;
    char c;

    while (1) {
        if (!(cin >> c))
            return 0;
        if (c == '#')
            break;
        n = (n * 2 + c - '0') % mod;
    }

    cout << (n ? "NO\n" : "YES\n");
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}