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

    n *= 2;
    int res = 0;

    for (long long d = 1; d * d <= n; d++) {
        if (n % d)
            continue;

        long long d2 = n / d;

        res += (d + d2) % 2 * 2;
    }

    cout << res;
}