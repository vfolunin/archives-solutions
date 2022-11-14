#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> getPrimes() {
    const int N = 1e6;
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

    vector<int> primes = getPrimes();
    l = lower_bound(primes.begin(), primes.end(), l) - primes.begin();
    r = upper_bound(primes.begin(), primes.end(), r) - primes.begin();

    if (l < r) {
        for (int i = l; i < r; i++)
            cout << primes[i] << "\n";
    } else {
        cout << "Absent";
    }
}