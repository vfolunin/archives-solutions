#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> getPrimes() {
    const int N = 4000;
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

int primeDivisorCount(int n) {
    static vector<int> primes = getPrimes();
    int res = 0;
    for (int i = 0; 1LL * primes[i] * primes[i] <= n; i++) {
        while (n % primes[i] == 0) {
            res++;
            n /= primes[i];
        }
    }
    res += n > 1;
    return res;
}

vector<int> prepare() {
    vector<int> res = { 1 };
    for (int i = 2; res.back() < 1e7; i++)
        res.push_back(res.back() + primeDivisorCount(i));
    return res;
}

void solve() {
    int n;
    cin >> n;

    static vector<int> res = prepare();

    cout << lower_bound(res.begin(), res.end(), 2 + n) - res.begin() + 1 << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}