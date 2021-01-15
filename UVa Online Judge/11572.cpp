#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

struct Counter {
    unordered_map<int, int> k;
    int repeatingElements;

    Counter() : repeatingElements(0) {}

    void inc(int x) {
        repeatingElements += (k[x]++ == 1);
    }

    void dec(int x) {
        repeatingElements -= (k[x]-- == 2);
    }

    bool ok() {
        return !repeatingElements;
    }
};

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int &x : a)
        cin >> x;

    int res = 0;

    Counter counter;
    for (int l = 0, r = 0; r < n; r++) {
        counter.inc(a[r]);
        while (!counter.ok())
            counter.dec(a[l++]);
        res = max(res, r - l + 1);
    }

    cout << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}