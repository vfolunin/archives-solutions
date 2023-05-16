#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <climits>
using namespace std;

map<int, int> factorize(int n) {
    map<int, int> factorization;

    for (long long d = 2; d * d <= n; d++) {
        while (n % d == 0) {
            factorization[d]++;
            n /= d;
        }
    }
    if (n != 1)
        factorization[n]++;

    return factorization;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int num, den;
    cin >> num >> den;

    int res = INT_MAX;
    for (auto [p, pPower] : factorize(den)) {
        int cur = num, fPower = 0;
        while (cur) {
            cur /= p;
            fPower += cur;
        }
        res = min(res, fPower / pPower);
    }

    cout << res;
}