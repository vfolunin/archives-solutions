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

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int l, r;
    cin >> l >> r;

    vector<int> primes = getPrimes(1e5), res;
    for (int p : primes) {
        if (l <= p && p <= r) {
            string s = to_string(p);
            if (s.front() == s.back())
                res.push_back(p);
        }
    }

    if (!res.empty()) {
        for (int p : res)
            cout << p << " ";
    } else {
        cout << 0;
    }
}