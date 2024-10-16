#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int m, n;
    if (!(cin >> m >> n))
        return 0;

    if (m == 0)
        cout << n + 1 << "\n";
    else if (m == 1)
        cout << n + 2 << "\n";
    else if (m == 2)
        cout << 2 * n + 3 << "\n";
    else
        cout << (1 << (n + 3)) - 3 << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}