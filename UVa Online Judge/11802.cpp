#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const long long MOD = 1e9 + 7;

vector<int> getPrimes() {
    const int N = 500;
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

void solve(int test) {
    long long n, z;
    cin >> n >> z;

    static vector<int> primes = getPrimes();
    long long resAdd = 1, resSub = 1;

    for (int p : primes) {
        long long k = 0;
        for (long long power = p; power <= n; power *= p)
            k += n / power;

        if (k < z)
            break;

        resAdd = (resAdd * (1 + k / z)) % MOD;
        resSub = (resSub * (1 + k / (z + 1))) % MOD;
    }

    cout << "Case " << test << ": " << (resAdd - resSub + MOD) % MOD << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}