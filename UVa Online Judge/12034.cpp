#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const long long MOD = 10056;

vector<vector<long long>> getC() {
    vector<vector<long long>> c(1001, vector<long long>(1001));
    for (int i = 0; i < c.size(); i++) {
        c[i][0] = 1;
        for (int j = 1; j <= i; j++)
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
    }
    return c;
}

vector<long long> prepare() {
    vector<long long> p(1001);
    p[0] = 1;
    static vector<vector<long long>> c = getC();
    for (int i = 1; i < p.size(); i++)
        for (int j = 1; j <= i; j++)
            p[i] = (p[i] + c[i][j] * p[i - j]) % MOD;
    return p;
}

void solve(int test) {
    int n;
    cin >> n;

    static vector<long long> p = prepare();
    cout << "Case " << test << ": " << p[n] << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}