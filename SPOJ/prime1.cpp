#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> getPrimes() {
    const int N = 1e5;
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

bool isPrime(int n) {
    if (n < 2)
        return 0;
    static vector<int> primes = getPrimes();
    for (int i = 0; 1LL * primes[i] * primes[i] <= n; i++)
        if (n % primes[i] == 0)
            return 0;
    return 1;
}

void solve() {
    int l, r;
    cin >> l >> r;

    for (int i = l; i <= r; i++)
        if (isPrime(i))
            cout << i << "\n";
    cout << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}