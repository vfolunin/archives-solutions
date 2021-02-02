#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

set<int> getPrimes() {
    vector<int> isPrime(1e5, 1);
    set<int> primes;
    for (long long i = 2; i < 1e5; i++) {
        if (isPrime[i]) {
            primes.insert(i);
            for (long long j = i * i; j < 1e5; j += i)
                isPrime[j] = 0;
        }
    }
    return primes;
}

bool solve() {
    int n;
    cin >> n;

    if (!n)
        return 0;

    static set<int> primes = getPrimes();

    int pairs = 0;
    for (int p : primes)
        if (p <= n - p && primes.count(n - p))
            pairs++;
    
    cout << pairs << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}