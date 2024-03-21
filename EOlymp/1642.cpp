#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
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

int factPower(int f, int p) {
    int res = 0;
    while (f) {
        f /= p;
        res += f;
    }
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (auto &[p, k] : factorize(n)) {
        if (factPower(n, p) < k + k) {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";
}