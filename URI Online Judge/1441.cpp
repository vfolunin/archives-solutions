#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int n;
    cin >> n;

    if (n == 0)
        return 0;

    int res = n;

    while (n > 1) {
        if (n % 2)
            n = 3 * n + 1;
        else
            n /= 2;
        res = max(res, n);
    }

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}