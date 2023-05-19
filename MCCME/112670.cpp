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

    int den, num;
    cin >> den >> num;

    map<int, int> fNum = factorize(num);
    int res = 1;

    for (auto &[d, p] : factorize(den)) {
        if (!fNum.count(d)) {
            cout << -1;
            return 0;
        }
        res = max(res, (p + fNum[d] - 1) / fNum[d]);
    }

    cout << res;
}