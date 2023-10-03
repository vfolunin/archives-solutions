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

int digitSquareSum(int n) {
    int res = 0;
    while (n) {
        res += (n % 10) * (n % 10);
        n /= 10;
    }
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int l, r;
    cin >> l >> r;

    int best = -1, bestSum = 0;
    for (int i = l; i <= r; i++) {
        if (!isPrime(i))
            continue;

        int sum = digitSquareSum(i);
        if (sum > bestSum) {
            best = i;
            bestSum = sum;
        }
    }

    cout << best;
}