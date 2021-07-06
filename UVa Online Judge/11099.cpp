#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> getPrimes() {
    const int N = 2000;
    vector<int> isPrime(N, 1);
    vector<int> primes;
    for (int i = 2; i < N; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (int j = i * i; j < N; j += i)
                isPrime[j] = 0;
        }
    }
    return primes;
}

int getBase(int n) {
    static vector<int> primes = getPrimes();
    int res = 1;
    for (int i = 0; i < primes.size() && primes[i] * primes[i] <= n; i++) {
        if (n % primes[i] == 0) {
            res *= primes[i];
            while (n % primes[i] == 0)
                n /= primes[i];
        }
    }
    return res * n;
}

bool solve() {
    long long n;
    if (!(cin >> n))
        return 0;

    if (n > 1) {
        long long base = getBase(n);
        for (int i = n / base + 1; base * i < 2e6; i++) {
            if (getBase(base * i) == base) {
                cout << base * i << "\n";
                return 1;
            }
        }
    }

    cout << "Not Exist!\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}