#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

void solve() {
    long long n;
    cin >> n;

    n *= 567;
    n /= 9;
    n += 7492;
    n *= 235;
    n /= 47;
    n -= 498;

    cout << abs(n) % 100 / 10 << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}