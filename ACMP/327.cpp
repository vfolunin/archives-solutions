#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool isLucky(int n) {
    int sum = 0;
    for (int i = 0; i < 6; i++) {
        sum += n % 10 * (i < 3 ? 1 : -1);
        n /= 10;
    }
    return !sum;
}

void solve() {
    int n;
    cin >> n;

    cout << (isLucky(n - 1) || isLucky(n + 1) ? "Yes\n" : "No\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}