#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int n;
    cin >> n;

    int divisorSum = 0;
    for (int d = 1; d < n; d++)
        if (n % d == 0)
            divisorSum += d;

    if (n > divisorSum)
        cout << "deficient\n";
    else if (n == divisorSum)
        cout << "perfect\n";
    else
        cout << "abundant\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}