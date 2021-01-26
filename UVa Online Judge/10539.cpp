#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<long long> getAlmostPrimes() {
    vector<bool> isPrime(1e6, 1);
    vector<long long> almostPrimes;
    for (int i = 2; i < 1e6; i++) {
        if (isPrime[i]) {
            for (long long j = 1LL * i * i; j < 1e6; j += i)
                isPrime[j] = 0;
            for (long long j = 1LL * i * i; j < 1e12; j *= i)
                almostPrimes.push_back(j);
        }
    }
    sort(almostPrimes.begin(), almostPrimes.end());
    return almostPrimes;
}

void solve() {
    long long l, r;
    cin >> l >> r;

    static vector<long long> p = getAlmostPrimes();
    cout << upper_bound(p.begin(), p.end(), r) - lower_bound(p.begin(), p.end(), l) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}