#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> getPrimes() {
    const int N = 1e4;
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

void solve() {
    int n;
    cin >> n;

    static vector<int> primes = getPrimes();

    int res = -1, resDiff = -1;
    for (int i = 0; i < primes.size() && primes[i] <= n; i++) {
        int prod = n / primes[i] * primes[i];
        int diff = n - prod;
        if (diff > resDiff) {
            resDiff = diff;
            res = primes[i];
        }
    }

    cout << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}