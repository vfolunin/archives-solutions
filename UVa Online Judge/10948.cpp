#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> getPrimes() {
    const int N = 1e6;
    vector<int> isPrime(N, 1);
    vector<int> primes;
    for (int i = 2; i < N; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (long long j = 1LL * i * i; j < N; j += i)
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

    cout << n << ":\n";

    static vector<int> primes = getPrimes();
    for (int i = 0, j = primes.size() - 1; i <= j; i++) {
        while (i <= j && primes[i] + primes[j] > n)
            j--;
        if (i <= j && primes[i] + primes[j] == n) {
            cout << primes[i] << "+" << primes[j] << "\n";
            return 1;
        }
    }

    cout << "NO WAY!\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}