#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

pair<int, int> rec(int n) {
    if (!n)
        return { 1, 1 };
    auto [num, den] = rec((n - 1) / 2);
    if (n % 2)
        return { num, num + den };
    else
        return { num + den, den };
}

void solve() {
    int test, n;
    cin >> test >> n;

    auto [num, den] = rec(n - 1);

    cout << test << " " << num << "/" << den << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}