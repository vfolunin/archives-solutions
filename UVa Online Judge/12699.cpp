#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<vector<double>> prepare() {
    const int N = 1e6 + 1;
    vector<double> d(N);
    vector<double> s(N);
    vector<double> a(N);

    d[1] = s[1] = a[1] = 1;
    for (int i = 2; i < N; i++) {
        if (i % 2 == 0) {
            d[i] = 1 + d[i / 2];
            s[i] = s[i / 2];
            a[i] = a[i / 2];
        } else {
            d[i] = (d[i - 1] + 1 + d[(i + 1) / 2]) / 2;
            s[i] = (1 + s[i - 1] + s[(i + 1) / 2]) / 2;
            a[i] = (a[i - 1] + 1 + a[(i + 1) / 2]) / 2;
        }
    }

    return { d, s, a };
}

void solve() {
    int n, d, s, a;
    cin >> n >> d >> s >> a;

    static vector<vector<double>> ops = prepare();
    double res = ops[0][n] * d + ops[1][n] * s + ops[2][n] * a;

    cout.precision(3);
    cout << fixed << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}