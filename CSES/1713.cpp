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

int divisorCount(int n) {
    static vector<int> primes = getPrimes();

    int res = 1;
    for (int i = 0; 1LL * primes[i] * primes[i] <= n; i++) {
        if (n % primes[i])
            continue;

        int power = 0;
        while (n % primes[i] == 0) {
            n /= primes[i];
            power++;
        }
        res *= power + 1;
    }
    if (n > 1)
        res *= 2;

    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int queryCount;
    cin >> queryCount;

    for (int i = 0; i < queryCount; i++) {
        int n;
        cin >> n;

        cout << divisorCount(n) << "\n";
    }
}