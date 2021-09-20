#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> getPrimes() {
    const int N = 1e4;
    vector<int> isPrime(N, 1), primes;
    for (int i = 2; i < N; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (int j = i * i; j < N; j += i)
                isPrime[j] = 0;
        }
    }
    return primes;
}

bool solve() {
    int n;
    if (!(cin >> n))
        return 0;

    static vector<int> primes = getPrimes();

    int res = 0;
    for (int l = 0, r = upper_bound(primes.begin(), primes.end(), n) - primes.begin() - 1; l <= r; r--) {
        int prod = primes[r];
        while (l <= r && prod * primes[l] <= n)
            prod *= primes[l++];
        res++;
    }

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}