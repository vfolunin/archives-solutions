#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<long long> prepare() {
    vector<long long> fib = { 1, 2 };
    for (int i = 2; i < 51; i++)
        fib.push_back(fib[i - 2] + fib[i - 1]);
    return fib;
}

void solve(int test) {
    int n;
    cin >> n;

    static vector<long long> fib = prepare();
    cout << "Scenario #" << test << ":\n" << fib[n] << "\n\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}