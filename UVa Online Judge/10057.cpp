#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int n;
    if (!(cin >> n))
        return 0;

    vector<int> a(n);
    for (int &x : a)
        cin >> x;

    sort(a.begin(), a.end());

    if (n % 2 || a[(n - 1) / 2] == a[n / 2]) {
        int m = a[n / 2];
        auto l = lower_bound(a.begin(), a.end(), m);
        auto r = upper_bound(a.begin(), a.end(), m);
        cout << m << " " << r - l << " 1\n";
    } else {
        int m1 = a[(n - 1) / 2];
        int m2 = a[n / 2];
        auto l = lower_bound(a.begin(), a.end(), m1);
        auto r = upper_bound(a.begin(), a.end(), m2);
        cout << m1 << " " << r - l << " " << m2 - m1 + 1 << "\n";
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}