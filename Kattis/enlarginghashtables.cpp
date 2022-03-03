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
    return 1;
}

bool solve() {
    long long n;
    cin >> n;

    if (!n)
        return 0;

    long long res = 2 * n;
    while (!isPrime(res))
        res++;

    cout << res;
    if (!isPrime(n))
        cout << " (" << n << " is not prime)";
    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}