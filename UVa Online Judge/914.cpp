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

void solve() {
    int l, r;
    cin >> l >> r;

    static vector<int> primes = getPrimes();

    map<int, int> diffCount;
    int maxDiffCount = 0;
    auto lIt = lower_bound(primes.begin(), primes.end(), l);
    auto rIt = upper_bound(primes.begin(), primes.end(), r);
    if (lIt != rIt) {
        for (auto it = lIt; next(it) != rIt; it++) {
            int diff = *next(it) - *it;
            diffCount[diff]++;
            maxDiffCount = max(maxDiffCount, diffCount[diff]);
        }
    }

    int mostFrequentDiff = -1;
    for (auto &[diff, count] : diffCount) {
        if (count == maxDiffCount) {
            if (mostFrequentDiff == -1) {
                mostFrequentDiff = diff;
            } else {
                mostFrequentDiff = -1;
                break;
            }
        }
    }

    if (mostFrequentDiff != -1)
        cout << "The jumping champion is " << mostFrequentDiff << "\n";
    else
        cout << "No jumping champion\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}