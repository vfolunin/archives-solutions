#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

pair<double, double> rec(int a, int b, int depth) {
    static vector<vector<vector<pair<double, double>>>> memo(301, vector<vector<pair<double, double>>>(301, vector<pair<double, double>>(101, { -1, -1 })));
    auto &[len, p] = memo[a][b][depth];
    if (len != -1)
        return { len, p };

    if (!a || !b) {
        len = 0;
        p = (bool)a;
        return { len, p };
    }

    if (depth == 100) {
        len = 0;
        p = 0.5;
        return { len, p };
    }

    int c = min(a, b);
    auto [lenA, pA] = rec(a + c, b - c, depth + 1);
    auto [lenB, pB] = rec(a - c, b + c, depth + 1);

    len = 1 + (lenA + lenB) / 2;
    p = (pA + pB) / 2;
    return { len, p };
}

void solve(int test) {
    int a, b;
    cin >> a >> b;

    auto [len, p] = rec(a, b, 0);

    cout << "Case " << test << ": ";
    cout << fixed << len << " " << p << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}