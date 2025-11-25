#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> getFib() {
    vector<int> fib = { 0, 1 };
    for (int i = 2; fib.back() <= 1e9; i++)
        fib.push_back(fib[i - 1] + fib[i - 2]);
    return fib;
}

bool solve() {
    int n;
    if (!(cin >> n))
        return 0;

    static vector<int> fib = getFib();
    auto r = upper_bound(fib.begin(), fib.end(), n);
    auto l = prev(r);

    cout << (n - *l < *r - n ? *l : *r) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}