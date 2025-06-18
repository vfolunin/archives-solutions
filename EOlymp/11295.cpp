#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long f(long long a, long long b) {
    return a * a * a + a * a * b + a * b * b + b * b * b;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long n;
    cin >> n;

    long long res = 1e18;
    for (long long l = 0, r = 1e6; l <= r; l++)
        for (; f(l, r) >= n && r >= 0; r--)
            res = min(res, f(l, r));

    cout << res;
}