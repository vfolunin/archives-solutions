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
    for (int d = 2; d * d <= n; d++)
        if (n % d == 0)
            return 0;
    return 1;
}

bool hasPrimeDigits(int n) {
    if (!n)
        return 1;
    return hasPrimeDigits(n / 10) && isPrime(n % 10);
}

bool solve() {
    int n;
    if (!(cin >> n))
        return 0;

    if (isPrime(n)) {
        if (hasPrimeDigits(n))
            cout << "Super\n";
        else
            cout << "Primo\n";
    } else {
        cout << "Nada\n";
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}