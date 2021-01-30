#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<long long> getPrimes() {
    vector<int> isPrime(1e7, 1);
    vector<long long> primes;
    for (long long i = 2; i < 1e7; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (long long j = i * i; j < 1e7; j += i)
                isPrime[j] = 0;
        }
    }
    return primes;
}

vector<long long> getPrimeDivisors(long long n) {
    static vector<long long> primes = getPrimes();
    vector<long long> primeDivisors;
    for (int i = 0; i < primes.size() && primes[i] * primes[i] <= n; i++) {
        if (n % primes[i] == 0) {
            primeDivisors.push_back(primes[i]);
            while (n % primes[i] == 0)
                n /= primes[i];
        }
    }
    if (n > 1)
        primeDivisors.push_back(n);
    return primeDivisors;
}

bool solve() {
    long long n;
    cin >> n;

    if (!n)
        return 0;

    vector<long long> primeDivisors = getPrimeDivisors(abs(n));

    if (primeDivisors.size() > 1)
        cout << primeDivisors.back() << "\n";
    else
        cout << "-1\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}