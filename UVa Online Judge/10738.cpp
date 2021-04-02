#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int getMu(int n) {
    int res = 1;
    for (int d = 2; d * d <= n; d++) {
        if (n % d)
            continue;
        n /= d;
        if (n % d == 0)
            return 0;
        res *= -1;
    }
    if (n != 1)
        res *= -1;
    return res;
}

pair<vector<int>, vector<int>> prepare() {
    const int N = 1e6 + 1;
    vector<int> mu(N), m(N);
    for (int i = 1; i < N; i++) {
        mu[i] = getMu(i);
        m[i] = m[i - 1] + mu[i];
    }
    return { mu, m };
}

bool solve() {
    int n;
    cin >> n;

    if (!n)
        return 0;

    static auto [mu, m] = prepare();

    cout << setw(8) << n << setw(8) << mu[n] << setw(8) << m[n] << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}