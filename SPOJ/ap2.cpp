#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    long long a, b, sum;
    cin >> a >> b >> sum;

    long long n = 2 * sum / (a + b);
    long long d = (b - a) / (n - 5);

    cout << n << "\n";
    for (long long i = 0, x = a - 2 * d; i < n; i++, x += d)
        cout << x << " ";
    cout << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}