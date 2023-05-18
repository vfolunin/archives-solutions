#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> getTwins(int n) {
    vector<int> minDivisor(n + 1), primes;

    for (int i = 2; i < minDivisor.size(); i++) {
        if (!minDivisor[i]) {
            minDivisor[i] = i;
            primes.push_back(i);
        }
        for (int j = 0; j < primes.size() && primes[j] <= minDivisor[i] && 1LL * i * primes[j] < minDivisor.size(); j++)
            minDivisor[i * primes[j]] = primes[j];
    }

    vector<int> twins;
    for (int i = 0; i < primes.size(); i++)
        if (i && primes[i] - primes[i - 1] == 2 || i + 1 < primes.size() && primes[i + 1] - primes[i] == 2)
            twins.push_back(primes[i]);
    return twins;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int l, r;
    cin >> l >> r;

    int res = 0;
    for (int value : getTwins(r + 2))
        res += l <= value && value <= r;

    cout << res;
}