#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int n, targetSum;
    if (!(cin >> n >> targetSum))
        return 0;

    vector<int> a(n);
    for (int &x : a)
        cin >> x;

    int res = n + 1, sum = 0;
    for (int l = 0, r = 0; l < n; l++) {
        while (r < n && sum < targetSum) {
            sum += a[r];
            r++;
        }
        if (sum >= targetSum)
            res = min(res, r - l);
        sum -= a[l];
    }

    cout << (res != n + 1 ? res : 0) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}