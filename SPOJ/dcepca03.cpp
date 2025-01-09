#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long phi(long long n) {
    long long res = n;
    for (long long d = 2; d * d <= n; d++) {
        if (n % d == 0) {
            while (n % d == 0)
                n /= d;
            res -= res / d;
        }
    }
    if (n > 1)
        res -= res / n;
    return res;
}

vector<long long> prepare() {
    vector<long long> a(1e4 + 1);
    for (int i = 1; i < a.size(); i++)
        a[i] = phi(i);

    vector<long long> res(a.size());
    for (int i = 1; i < a.size(); i++) {
        res[i] = res[i - 1] + a[i] * a[i];
        for (int j = 1; j < i; j++)
            res[i] += 2 * a[i] * a[j];
    }
    return res;
}

void solve() {
    int n;
    cin >> n;

    static vector<long long> res = prepare();

    cout << res[n] << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}