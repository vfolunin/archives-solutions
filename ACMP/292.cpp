#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool isPrime(int n) {
    if (n < 2)
        return 0;

    for (long long d = 2; d * d <= n; d++)
        if (n % d == 0)
            return 0;

    return 1;
}

int digitalPrimeRoot(int n) {
    if (isPrime(n))
        return n;

    if (n < 10)
        return 0;

    int sum = 0;
    while (n) {
        sum += n % 10;
        n /= 10;
    }
    return digitalPrimeRoot(sum);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    cout << digitalPrimeRoot(n);
}