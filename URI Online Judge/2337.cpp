#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

vector<long long> prepare() {
    vector<long long> fib = { 1, 2 };
    for (int i = 2; i <= 40; i++)
        fib.push_back(fib[i - 1] + fib[i - 2]);
    return fib;
}

bool solve() {
    int roundCount;
    if (!(cin >> roundCount))
        return 0;

    static vector<long long> fib = prepare();
    long long num = fib[roundCount];
    long long den = 1LL << roundCount;

    long long g = gcd(num, den);
    num /= g;
    den /= g;

    cout << num << "/" << den << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}