#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int evenTo(int r) {
    return r / 2 + 1;
}

int evenBetween(int l, int r) {
    return evenTo(r) - (l ? evenTo(l - 1) : 0);
}

void solve(int test) {
    int a1, a2, b1, b2, c1, c2;
    cin >> a1 >> a2 >> b1 >> b2 >> c1 >> c2;

    long long a = evenBetween(a1, a2);
    long long b = b2 - b1 + 1;
    long long c = evenBetween(c1, c2);

    cout << "Case " << test << ": " << a * b * c << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}