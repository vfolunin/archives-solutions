#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    long long k, c;
    int n;
    cin >> k >> c >> n;

    vector<long long> a(n);
    cin >> a[0];
    for (int i = 1; i < n; i++)
        a[i] = (k * a[i - 1] + c) % 1000007;

    sort(a.begin(), a.end());

    vector<long long> p = a;
    for (int i = 1; i < n; i++)
        p[i] += p[i - 1];

    long long res = 0;
    for (int i = 1; i < n; i++)
        res += i * a[i] - p[i - 1];

    cout << "Case " << test << ": " << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}