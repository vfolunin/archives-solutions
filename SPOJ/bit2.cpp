#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int ones(long long n) {
    int res = 0;
    while (n) {
        res++;
        n &= n - 1;
    }
    return res;
}

long long onesTo(long long n) {
    if (!n)
        return 0;

    if (n % 2)
        return onesTo(n / 2) * 2 + (n + 1) / 2;
    else
        return onesTo(n - 1) + ones(n);
}

void solve() {
    long long count;
    cin >> count;

    long long l = 0, r = 1;
    while (onesTo(r) < count)
        r *= 2;

    while (l + 1 < r) {
        long long m = l + (r - l) / 2;
        if (onesTo(m) < count)
            l = m;
        else
            r = m;
    }

    if (onesTo(r) == count)
        cout << r << "\n";
    else
        cout << "Does Not Exist.\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}