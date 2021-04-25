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

long long lcm(long long a, long long b) {
    return a / gcd(a, b) * b;
}

void solve(int test) {
    int n;
    cin >> n;

    long long res = 1;
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        res = lcm(res, x);
    }

    cout << "Case " << test << ": " << 35 * res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}