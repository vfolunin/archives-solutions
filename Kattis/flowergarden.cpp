#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> getPrimes() {
    const int N = 2e4;
    vector<int> isPrime(N, 1);
    vector<int> primes = { 0 };
    for (int i = 2; i < N; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (long long j = 1LL * i * i; j < N; j += i)
                isPrime[j] = 0;
        }
    }
    return primes;
}

void solve() {
    int pointCount, maxDist;
    cin >> pointCount >> maxDist;

    vector<double> dist = { 0 };
    int x1, y1, x2 = 0, y2 = 0;

    for (int i = 0; i < pointCount; i++) {
        x1 = x2;
        y1 = y2;
        cin >> x2 >> y2;
        dist.push_back(dist.back() + hypot(x1 - x2, y1 - y2));
    }

    int res = upper_bound(dist.begin(), dist.end(), maxDist) - dist.begin() - 1;
    static vector<int> primes = getPrimes();
    res = *--upper_bound(primes.begin(), primes.end(), res);

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