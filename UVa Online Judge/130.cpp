#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Circle {
    vector<int> a;
    int n, k, pos;

    Circle(int n, int k) : n(n), k(k) {
        for (int i = 1; i <= n; i++)
            a.push_back(i);
        pos = n - 1;
    }

    void skipZeros() {
        while (!a[pos])
            pos = (pos + 1) % a.size();
    }

    void inc(int k) {
        skipZeros();
        for (int i = 0; i < k; i++) {
            pos = (pos + 1) % a.size();
            skipZeros();
        }
    }

    int getLast() {
        for (int i = 0; i < n - 1; i++) {
            inc(k);
            a[pos] = 0;
            int to = pos;

            inc(k - 1);
            swap(a[pos], a[to]);
            pos = to;
        }
        return a[pos];
    }
};

bool solve() {
    int n, k;
    cin >> n >> k;

    if (!n && !k)
        return 0;

    int last = Circle(n, k).getLast();
    int res = (last == 1 ? 1 : n + 2 - last);

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}