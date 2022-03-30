#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long count(long long n, int d) {
    long long res = 0;
    while (n > 0) {
        res += n % 10 == d;
        n /= 10;
    }
    return res;
}

long long countTo(long long n, int d) {
    long long res = 0;
    if (n < 10) {
        while (n > 0) {
            res += count(n, d);
            n--;
        }
    } else {
        while (n % 10 != 9) {
            res += count(n, d);
            n--;
        }
        res += n / 10 + (bool)d + countTo(n / 10, d) * 10;
    }
    return res;
}

long long count(long long l, long long r, int d) {
    return countTo(r, d) - countTo(l - 1, d);
}

long long sum(long long l, long long r) {
    long long res = 0;
    for (int d = 1; d < 10; d++)
        res += count(l, r, d) * d;
    return res;
}

void solve() {
    long long l, r;
    cin >> l >> r;

    cout << sum(l, r) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}