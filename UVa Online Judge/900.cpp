#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<long long> prepareFib() {
    vector<long long> fib = { 1, 1 };
    while (fib.size() <= 50)
        fib.push_back(fib[fib.size() - 2] + fib.back());
    return fib;
}

bool solve() {
    int n;
    cin >> n;

    if (!n)
        return 0;

    static vector<long long> fib = prepareFib();
    cout << fib[n] << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}