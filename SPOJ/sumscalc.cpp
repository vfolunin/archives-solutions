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

    vector<long long> a(5);
    for (long long i = 1; i <= n; i++) {
        a[0] += i;
        a[1] += 2 * i;
        a[2] += 2 * i - 1;
        a[3] += i * i;
        a[4] += i * i * i;
    }

    for (int i = 0; i < a.size(); i++)
        cout << a[i] << (i + 1 < a.size() ? " " : "\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}