#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    long long sum, diff;
    cin >> sum >> diff;

    long long a = (sum + diff) / 2;
    long long b = sum - a;

    if (a >= 0 && b >= 0 && a + b == sum && abs(a - b) == diff)
        cout << a << " " << b << "\n";
    else
        cout << "impossible\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}