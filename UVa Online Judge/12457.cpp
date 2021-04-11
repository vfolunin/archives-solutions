#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<vector<long long>> getC() {
    vector<vector<long long>> c(50, vector<long long>(50));
    for (int i = 0; i < c.size(); i++) {
        c[i][0] = 1;
        for (int j = 1; j <= i; j++)
            c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
    }
    return c;
}

void solve() {
    int wins;
    double winProb;
    cin >> wins >> winProb;

    static vector<vector<long long>> c = getC();

    double res = 0;
    for (int losses = 0; losses < wins; losses++)
        res += c[wins + losses - 1][wins - 1] * pow(winProb, wins) * pow(1 - winProb, losses);

    cout.precision(2);
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