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

    int sum, p;
    cin >> sum >> p;

    if (p >= 15) {
        cout << sum;
        return 0;
    }

    vector<int> res(sum + 1);
    for (int i = 1; i < res.size(); i++) {
        res[i] = i;
        for (int j = 1; binPow(j, p) <= i; j++)
            res[i] = min(res[i], res[i - binPow(j, p)] + 1);
    }

    cout << res[sum];
}