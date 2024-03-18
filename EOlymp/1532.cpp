#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long getCatalan(int n) {
    vector<long long> res = { 1 };
    for (int i = 1; i <= n; i++) {
        res.push_back(0);
        for (int j = 0; j < i; j++)
            res.back() += res[j] * res[i - 1 - j];
    }
    return res.back();
}

bool solve() {
    int n;
    if (!(cin >> n))
        return 0;

    cout << getCatalan(n / 2) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}