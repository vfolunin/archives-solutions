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

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    long long len = 0, res = 1;
    for (auto &[p, k] : factorize(n)) {
        for (int i = 1; i <= k; i++)
            res *= ++len;
        for (int i = 1; i <= k; i++)
            res /= i;
    }

    cout << res;
}