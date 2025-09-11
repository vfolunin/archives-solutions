#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> getPrimes(int n) {
    vector<int> isPrime(n + 1, 1), primes;

    for (int i = 2; i < isPrime.size(); i++) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (long long j = 1LL * i * i; j < isPrime.size(); j += i)
                isPrime[j] = 0;
        }
    }

    return primes;
}

int getDivisorSum(int n) {
    int sum = 0;
    for (long long d = 1; d * d <= n; d++) {
        if (n % d == 0) {
            sum += d;
            if (d * d != n && d != 1)
                sum += n / d;
        }
    }
    return sum;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int l, r;
    cin >> l >> r;

    if (l == 1) {
        cout << 1;
        return 0;
    }

    vector<int> primes = getPrimes(r);
    if (l <= primes.back()) {
        cout << primes.back();
        return 0;
    }

    int res = l, resSum = getDivisorSum(res);
    for (int i = l + 1; i <= r; i++) {
        int iSum = getDivisorSum(i);
        if (1LL * resSum * i > 1LL * iSum * res) {
            res = i;
            resSum = iSum;
        }
    }

    cout << res;
}