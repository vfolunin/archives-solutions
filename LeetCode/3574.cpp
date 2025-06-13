#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;

        a[i] = x * y;
    }

    int cur = 0;
    for (int i = 0; i < k; i++)
        cur += a[i];

    int res = cur;
    for (int i = k; i < n; i++) {
        cur += a[i] - a[i - k];
        res = max(res, cur);
    }

    cout << res;
}