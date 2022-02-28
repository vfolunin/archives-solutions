#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> getMinDivisor() {
    const int N = 2e6 + 1;
    vector<int> minDivisor(N), primes;

    for (int i = 2; i < N; i++) {
        if (!minDivisor[i]) {
            minDivisor[i] = i;
            primes.push_back(i);
        }
        for (int j = 0; j < primes.size() && primes[j] <= minDivisor[i] && 1LL * i * primes[j] < N; j++)
            minDivisor[i * primes[j]] = primes[j];
    }

    return minDivisor;
}

int npf(int n) {
    static vector<int> minDivisor = getMinDivisor();

    map<int, int> factorization;
    while (n > 1) {
        factorization[minDivisor[n]]++;
        n /= minDivisor[n];
    }

    int res = 1;
    for (auto &[divisor, count] : factorization)
        res *= count + 1;
    res -= factorization.size();

    return res;
}

void solve() {
    int n;
    cin >> n;

    cout << npf(n) << "\n";
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