#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long gcd(long long a, long long b) {
    return b ? gcd(b, a % b) : a;
}

void solve(int test) {
    long long k;
    cin >> k >> k;

    long long num = (1LL << k) - k - 1;
    long long den = (1LL << k);

    long long d = gcd(num, den);
    num /= d;
    den /= d;

    cout << "Case #" << test << ": " << num << "/" << den << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}