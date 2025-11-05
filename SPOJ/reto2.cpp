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

    long long l1, r1, l2, r2, t;
    cin >> l1 >> r1 >> l2 >> r2 >> t;

    l1 = max(l1, l2);
    r1 = min(r1, r2);

    if (l1 <= r1) {
        long long res = r1 - l1 + 1;
        res -= l1 <= t && t <= r1;

        cout << res;
    } else {
        cout << 0;
    }
}