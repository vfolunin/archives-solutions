#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool can(int limit, vector<int> &a, int level) {
    for (int value : a) {
        if (value <= level)
            continue;
        if (limit >= value - level)
            limit -= value - level;
        else
            return 0;
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int limit, size;
    cin >> limit >> size;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    int l = -1, r = 2e9 + 1;
    while (l + 1 < r) {
        int m = l + (r - l) / 2;
        if (can(limit, a, m))
            r = m;
        else
            l = m;
    }

    for (int &value : a) {
        if (value > r) {
            limit -= value - r;
            value = r;
        }
    }

    long long res = 0;
    const long long MOD = 1e9 + 7;
    for (int &value : a) {
        if (value == r && limit) {
            value--;
            limit--;
        }
        res = (res + 1LL * value * value) % MOD;
    }

    cout << res;
}