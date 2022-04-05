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

    for (long long count = 2; 1; count++) {
        long long sum = count * (count + 1) / 2;
        if (sum > n)
            break;

        if ((n - sum) % count == 0) {
            cout << n << " = ";
            long long from = (n - sum) / count;
            for (long long i = 1; i <= count; i++)
                cout << from + i << (i < count ? " + " : "\n");
            return;
        }
    }

    cout << "IMPOSSIBLE\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}