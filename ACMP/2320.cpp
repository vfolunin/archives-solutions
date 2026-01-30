#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> getMinDivisor(int n) {
    vector<int> minDivisor(n + 1), primes;

    for (int i = 2; i < minDivisor.size(); i++) {
        if (!minDivisor[i]) {
            minDivisor[i] = i;
            primes.push_back(i);
        }
        for (int j = 0; j < primes.size() && primes[j] <= minDivisor[i] && 1LL * i * primes[j] < minDivisor.size(); j++)
            minDivisor[i * primes[j]] = primes[j];
    }

    return minDivisor;
}

void solve() {
    int n;
    cin >> n;

    static vector<int> minDivisor = getMinDivisor(1e6);

    cout << n << " = ";

    vector<int> divisors;
    for (; n > 1; n /= minDivisor[n])
        divisors.push_back(minDivisor[n]);

    if (divisors.empty())
        divisors.push_back(1);

    for (int i = 0; i < divisors.size(); i++)
        cout << divisors[i] << (i + 1 < divisors.size() ? "*" : "\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}