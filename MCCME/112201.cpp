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

bool isHyperprime(int n) {
    while (n) {
        if (!isPrime(n))
            return 0;
        n /= 10;
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int l, r;
    cin >> l >> r;

    bool found = 0;
    for (int i = l; i <= r; i++) {
        if (isHyperprime(i)) {
            cout << i << " ";
            found = 1;
        }
    }

    if (!found)
        cout << 0;
}