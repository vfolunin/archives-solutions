#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool isPrime(long long n) {
    for (long long d = 2; d * d <= n; d++)
        if (n % d == 0)
            return 0;
    return n > 1;
}

bool isHappy(long long n) {
    if (n < 10)
        return n == 1 || n == 7;
    int digitSquareSum = 0;
    while (n) {
        digitSquareSum += (n % 10) * (n % 10);
        n /= 10;
    }
    return isHappy(digitSquareSum);
}

void solve() {
    int test, n;
    cin >> test >> n;

    cout << test << " " << n << (isPrime(n) && isHappy(n) ? " YES\n" : " NO\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}