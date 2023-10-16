#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long n;
    cin >> n;

    long long res = 1e18;
    for (int h = 1; h * h <= n; h++) {
        long long w = n / h;

        long long cur = (h + 1) * w + (w + 1) * h;
        if (n % h)
            cur += 3 + (n % h - 1) * 2;

        res = min(res, cur);
    }

    cout << res;
}