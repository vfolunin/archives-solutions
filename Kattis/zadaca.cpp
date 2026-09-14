#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

void factorize(int n, unordered_map<int, int> &factorization) {
    for (long long d = 2; d * d <= n; d++) {
        while (n % d == 0) {
            factorization[d]++;
            n /= d;
        }
    }
    if (n != 1)
        factorization[n]++;
}

unordered_map<int, int> getFactorization() {
    int size;
    cin >> size;

    unordered_map<int, int> factorization;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        factorize(value, factorization);
    }

    return factorization;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    unordered_map<int, int> fa = getFactorization();
    unordered_map<int, int> fb = getFactorization();

    const long long MOD = 1e9;
    bool reachedMod = 0;
    long long res = 1;

    for (auto &[p, countA] : fa) {
        int count = min(countA, fb[p]);
        for (int i = 0; i < count; i++) {
            res *= p;
            reachedMod |= res >= MOD;
            res %= MOD;
        }
    }

    if (reachedMod)
        cout << setw(9) << setfill('0');
    cout << res;
}