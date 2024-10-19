#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<long long> getFib() {
    vector<long long> fib = { 1, 2 };
    for (int i = 2; fib.back() < 5e18; i++)
        fib.push_back(fib[i - 2] + fib[i - 1]);
    return fib;
}

bool solve() {
    long long n;
    if (!(cin >> n))
        return 0;

    static vector<long long> fib = getFib();

    cout << n << "\n";

    vector<int> res;
    for (int i = fib.size() - 1; i >= 0; i--) {
        if (n >= fib[i]) {
            n -= fib[i];
            res.push_back(i);
        }
    }

    for (int i : res)
        cout << i + 1 << " ";
    cout << "\n";
    for (int i : res)
        cout << fib[i] << " ";
    cout << "\n\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}