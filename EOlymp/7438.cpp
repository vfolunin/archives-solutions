#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    vector<long long> fib = { 1, 2 }, pow = { 1, 2 };
    for (int i = 2; i <= n; i++) {
        fib.push_back(fib[i - 1] + fib[i - 2]);
        pow.push_back(pow.back() * 2);
    }

    long long num = pow[n];
    long long den = fib[n];

    long long g = gcd(num, den);
    num /= g;
    den /= g;

    cout << num << "/" << den;
}