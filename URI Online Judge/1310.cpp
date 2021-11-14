#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int n, cost;
    if (!(cin >> n >> cost))
        return 0;

    int res = 0, cur = 0;
    for (int i = 0; i < n; i++) {
        int profit;
        cin >> profit;
        cur = max(0, cur + profit - cost);
        res = max(res, cur);
    }

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}