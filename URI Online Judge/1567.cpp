#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long pow(long long n, int p) {
    long long res = n;
    for (int i = 1; i < p; i++)
        res *= n;
    return res;
}

vector<vector<long long>> prepare() {
    vector<vector<long long>> res(101, vector<long long>(6));
    for (long long i = 1; i <= 100; i++) {
        res[i][0] = res[i - 1][0] + pow(i, 2);
        res[i][2] = res[i - 1][2] + pow(i, 3);
        res[i][4] = res[i - 1][4] + pow(i, 4);
        res[i][1] = pow(i * (i + 1) / 2, 2) - res[i][0];
        res[i][3] = pow(i * (i + 1) / 2, 3) - res[i][2];
        res[i][5] = pow(i * (i + 1) / 2, 4) - res[i][4];
    }
    return res;
}

bool solve() {
    int n;
    if (!(cin >> n))
        return 0;

    static vector<vector<long long>> res = prepare();

    for (int i = 0; i < 6; i++)
        cout << res[n][i] << (i < 5 ? ' ' : '\n');
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}