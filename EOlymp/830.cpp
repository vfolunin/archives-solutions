#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> getPrimes() {
    const int N = 3e5;
    vector<int> isPrime(N, 1), primes;

    for (int i = 2; i < N; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (long long j = 1LL * i * i; j < N; j += i)
                isPrime[j] = 0;
        }
    }

    return primes;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int l, r;
    cin >> l >> r;

    vector<int> primes = getPrimes(), res;
    for (int p : primes)
        if (l <= p && p <= r)
            res.push_back(p);

    if (!res.empty()) {
        for (int p : res)
            cout << p << "\n";
    } else {
        cout << "Absent";
    }
}