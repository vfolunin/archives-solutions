#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int n, p;
    if (!(cin >> n >> p))
        return 0;

    int res = 0;
    for (int i = 1; i <= n; i++)
        for (int j = i / p; j; j /= p)
            res += j;

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}