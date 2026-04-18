#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int getCount(int t, int t1, int t2, int dt1, int dt2) {
    int res = 0;
    if (t >= t1) {
        int count = (t - t1) / dt1 + 1;
        t -= count * dt1;
        res += count;
    }
    if (t >= t2) {
        int count = (t - t2) / dt2 + 1;
        res += count;
    }
    return res;
}

void solve() {
    int t, t1, t2, dt1, dt2;
    cin >> t >> t1 >> t2 >> dt1 >> dt2;

    cout << max(getCount(t, t1, t2, dt1, dt2), getCount(t, t2, t1, dt2, dt1)) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}