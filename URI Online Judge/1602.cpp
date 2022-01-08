#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> prepare() {
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

    vector<int> divisorCount = { 0, 1 }, hyperprimes;
    for (int i = 2; i < N; i++) {
        int n = i, power = 0;
        while (n % minDivisor[i] == 0) {
            n /= minDivisor[i];
            power++;
        }
        divisorCount.push_back(divisorCount[n] * (power + 1));
        if (divisorCount[n] == 1 && binary_search(primes.begin(), primes.end(), power + 1))
            hyperprimes.push_back(i);
    }
    return hyperprimes;
}

bool solve() {
    int n;
    if (!(cin >> n))
        return 0;

    static vector<int> p = prepare();

    cout << upper_bound(p.begin(), p.end(), n) - p.begin() << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}