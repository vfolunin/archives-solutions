#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

inline int d(int a, int b) {
    return abs(a - b);
}

bool solve() {
    int n;
    cin >> n;

    if (!n)
        return 0;

    vector<int> l(n), r(n);
    for (int i = 0; i < n; i++)
        cin >> l[i] >> r[i];

    vector<int> costL(n), costR(n);
    costL[0] = abs(1 - r[0]) + abs(l[0] - r[0]);
    costR[0] = abs(1 - r[0]);

    for (int i = 1; i < n; i++) {
        costL[i] = min(costL[i - 1] + min(d(l[i - 1], l[i]) + d(l[i], r[i]), d(l[i - 1], r[i])),
                       costR[i - 1] + min(d(r[i - 1], l[i]) + d(l[i], r[i]), d(r[i - 1], r[i]))) + d(l[i], r[i]);
        costR[i] = min(costL[i - 1] + min(d(l[i - 1], l[i]), d(l[i - 1], r[i]) + d(l[i], r[i])),
                       costR[i - 1] + min(d(r[i - 1], l[i]), d(r[i - 1], r[i]) + d(l[i], r[i]))) + d(l[i], r[i]);
    }
    int res = n - 1 + min(costL[n - 1] + d(l[n - 1], r[n - 1]), costR[n - 1]) + d(r[n - 1], n);

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}