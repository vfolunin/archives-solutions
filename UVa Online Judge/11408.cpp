#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const int N = 5e6 + 1;

vector<int> getMinDivisor() {
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

int primeFactorSum(int n) {
    int sum = 0;
    static vector<int> minDivisor = getMinDivisor();
    while (n > 1) {
        int m = minDivisor[n];
        sum += m;
        while (n % m == 0)
            n /= m;
    }
    return sum;
}

vector<int> getDeprimes() {
    vector<int> deprimes;
    static vector<int> minDivisor = getMinDivisor();
    for (int i = 2; i < N; i++) {
        int pfs = primeFactorSum(i);
        if (minDivisor[pfs] == pfs)
            deprimes.push_back(i);
    }
    return deprimes;
}

bool solve() {
    int l, r;
    if (!(cin >> l >> r))
        return 0;

    static vector<int> p = getDeprimes();

    cout << upper_bound(p.begin(), p.end(), r) - lower_bound(p.begin(), p.end(), l) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}