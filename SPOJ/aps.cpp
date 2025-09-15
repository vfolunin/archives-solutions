#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
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

vector<long long> prepare() {
    vector<int> minDivisor = getMinDivisor(1e7);
    vector<long long> res(minDivisor.begin(), minDivisor.end());
    for (int i = 1; i < res.size(); i++)
        res[i] += res[i - 1];
    return res;
}

void solve() {
    int index;
    cin >> index;

    static vector<long long> res = prepare();

    cout << res[index] << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}