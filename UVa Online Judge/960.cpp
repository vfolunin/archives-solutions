#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool isPrime(int n) {
    if (n < 2)
        return 0;
    for (int d = 2; d * d <= n; d++)
        if (n % d == 0)
            return 0;
    return 1;
}

void solve() {
    int a, b;
    cin >> a >> b;

    if (a && b)
        cout << (isPrime(a * a + b * b) ? "P\n" : "C\n");
    else
        cout << (abs(a + b) % 4 == 3 && isPrime(abs(a + b)) ? "P\n" : "C\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}