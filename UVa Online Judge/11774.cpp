#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

void solve(int test) {
    int a, b;
    cin >> a >> b;

    cout << "Case " << test << ": " << (a + b) / gcd(a, b) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}