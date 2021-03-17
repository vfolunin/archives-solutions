#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

pair<vector<int>, vector<int>> prepare() {
    vector<int> d(100001), s(100001);
    for (int i = 1; i < d.size(); i++) {
        for (int j = 1; j * j <= i; j++) {
            if (i % j == 0) {
                d[i]++;
                s[i] += j;
                if (j * j != i) {
                    d[i]++;
                    s[i] += i / j;
                }
            }
        }
    }
    return { d, s };
}

void solve() {
    int l, r, k;
    cin >> l >> r >> k;

    static auto [d, s] = prepare();

    long long dSum = 0, sSum = 0;
    for (int i = l; i <= r; i++) {
        if (i % k == 0) {
            dSum += d[i];
            sSum += s[i];
        }
    }

    cout << dSum << " " << sSum << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}