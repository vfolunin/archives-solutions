#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void check(long long a, long long b, vector<pair<long long, long long>> &res) {
    long long root = sqrt(b);
    if (root > 1 && root * root == b)
        res.push_back({ root - 1, a * (root - 1) });
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long n;
    cin >> n;

    vector<pair<long long, long long>> res;

    for (long long d = 1; d * d <= n; d++) {
        if (n % d)
            continue;

        check(d, n / d, res);
        if (d * d < n)
            check(n / d, d, res);
    }

    if (res.empty()) {
        cout << "NO SOLUTION";
    } else {
        sort(res.begin(), res.end());
        for (auto &[a, b] : res)
            cout << a << " " << b << "\n";
    }
}