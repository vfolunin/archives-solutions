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

    long long n, k1, k2, p1, p2, p3;
    cin >> n >> k1 >> k2 >> p1 >> p2 >> p3;

    long long res = 0;

    if (n >= p1) {
        res += k1;
        n -= p1;

        long long t = min(k2, (n + p2 - 1) / p2);
        res += t;
        n -= t * p2;

        if (n > 0)
            res += (n + p3 - 1) / p3;
    }

    cout << res;
}