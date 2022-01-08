#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    vector<int> a(3), b(3);
    cin >> a[0] >> a[1] >> a[2] >> b[0] >> b[1] >> b[2];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int res = 0;
    do {
        do {
            if (a[0] < b[0] && a[1] < b[1])
                res |= 1;
            if (a[0] > b[0] && a[1] > b[1])
                res |= 2;
        } while (next_permutation(b.begin(), b.end()));
    } while (next_permutation(a.begin(), a.end()));

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