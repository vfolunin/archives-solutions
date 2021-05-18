#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Counter {
    map<int, int> count;
    int duplicateCount = 0;

    void inc(int x) {
        duplicateCount += count[x]++ == 1;
    }

    void dec(int x) {
        duplicateCount -= --count[x] == 1;
    }

    bool ok() {
        return !duplicateCount;
    }
};

void solve() {
    int n;
    cin >> n;

    vector<int> v(n);
    for (int &x : v)
        cin >> x;

    long long res = 0;
    Counter counter;

    for (int l = 0, r = 0; r < n; r++) {
        counter.inc(v[r]);
        while (!counter.ok())
            counter.dec(v[l++]);
        res += r - l + 1;
    }

    cout << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}