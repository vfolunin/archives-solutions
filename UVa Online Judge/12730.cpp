#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int n, dist;
    cin >> n >> dist;

    vector<double> res(n + 1), pRes(n + 1);
    for (int i = 1; i <= n; i++) {
        res[i] = (i <= dist + 1 ? 1 : 1 + pRes[i - dist - 1] * 2 / i);
        pRes[i] = res[i] + pRes[i - 1];
    }

    cout.precision(4);
    cout << "Case #" << test << ": " << fixed << res[n] << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}