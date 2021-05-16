#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<long long> getFib() {
    vector<long long> fib = { 1, 2 };
    while (fib.back() <= 2e9)
        fib.push_back(fib[fib.size() - 2] + fib[fib.size() - 1]);
    return fib;
}

int fibCount(long long n) {
    static vector<long long> fib = getFib();
    long long sum = 0;
    int count = 0;
    for (int i = lower_bound(fib.begin(), fib.end(), n) - fib.begin(); i >= 0; i--) {
        if (sum + fib[i] <= n) {
            sum += fib[i];
            count++;
        }
    }
    return count;
}

void solve(int test) {
    int dimensionCount;
    cin >> dimensionCount;

    long long res = 1;
    for (int i = 0; i < dimensionCount; i++) {
        int n;
        cin >> n;
        res *= fibCount(n);
    }

    cout << "Case " << test << ": " << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}