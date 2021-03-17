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

    long long res = 0;
    for (long long i = 1; i * i <= n; i++) {
        if (n / i != i)
            res += n / i;
        res += (n / i - n / (i + 1)) * i;
    }

    cout << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}