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

bool solve() {
    int n;
    if (!(cin >> n))
        return 0;

    static vector<int> minDiv = getMinDivisor();

    int res = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        res += x > 1 && minDiv[x] != x && minDiv[x / minDiv[x]] == x / minDiv[x];
    }

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}