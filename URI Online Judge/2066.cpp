#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long binPow(long long x, long long p) {
    if (!p)
        return 1;
    if (p % 2)
        return binPow(x, p - 1) * x;
    long long r = binPow(x, p / 2);
    return r * r;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<long long> res(19), res0(19);
    for (int i = 2; i < res.size(); i++) {
        res[i] = res0[i - 2] * 9;
        res0[i] = res0[i - 2] * 10;
        for (int d = 1; d < 9; d++)
            res[i] += binPow(10, i - 2) * (9 - d);
        for (int d = 0; d < 9; d++)
            res0[i] += binPow(10, i - 2) * (9 - d);
    }

    int n;
    cin >> n;

    cout << res[n] << "\n";
}