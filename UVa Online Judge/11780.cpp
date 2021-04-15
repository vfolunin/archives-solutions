#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> getFib() {
    vector<int> fib = { 1, 1 };
    for (int i = 2; fib.back() <= 1000; i++)
        fib.push_back(fib[i - 1] + fib[i - 2]);
    return fib;
}

vector<double> prepare() {
    static vector<int> fib = getFib();
    vector<double> res = { 0, 0.4 };
    for (int i = 2; i <= 1000; i++) {
        res.push_back(1e9);
        auto it = lower_bound(fib.begin(), fib.end(), i);
        if (*it == i)
            res.back() = min(res.back(), abs(*next(it) - 1.6 * i));
        for (int j = 1; j <= i - j; j++)
            res.back() = min(res.back(), res[j] + res[i - j]);
    }
    return res;
}

bool solve() {
    int n;
    cin >> n;

    if (!n)
        return 0;

    static vector<double> res = prepare();

    cout.precision(2);
    cout << fixed << res[n] << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}