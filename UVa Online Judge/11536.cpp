#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Counter {
    vector<int> count;
    int uniqueCount = 0;

    Counter(int k) : count(k) {}

    void inc(int x) {
        if (x < count.size())
            uniqueCount += !count[x]++;
    }

    void dec(int x) {
        if (x < count.size())
            uniqueCount -= !--count[x];
    }
};

void solve(int test) {
    int n, mod, k;
    cin >> n >> mod >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        if (i < 3)
            a[i] = i + 1;
        else
            a[i] = (a[i - 3] + a[i - 2] + a[i - 1]) % mod + 1;
    }

    Counter counter(k);
    int res = 1e9;
    for (int l = 0, r = 0; l < n; l++) {
        while (r < n && counter.uniqueCount < k)
            counter.inc(a[r++] - 1);
        if (counter.uniqueCount == k)
            res = min(res, r - l);
        counter.dec(a[l] - 1);
    }

    cout << "Case " << test << ": ";
    if (res != 1e9)
        cout << res << "\n";
    else
        cout << "sequence nai\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}