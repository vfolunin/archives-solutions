#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    long long n;
    cin >> n;

    long long d2 = 1;
    while (n / d2 % 10 == 0)
        d2 *= 2;

    long long d5 = 1;
    while (n / d5 % 10 == 0)
        d5 *= 5;

    long long d = min(d2, d5);

    cout << d << " " << n / d << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}