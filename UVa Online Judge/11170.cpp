#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<vector<long long>> prepare() {
    vector<vector<long long>> coeff = { { 1 }, { 0, 1 } };
    for (int i = 2; i <= 50; i++) {
        coeff.emplace_back(coeff[i - 1].size() + 1);
        for (int j = 0; j < coeff[i - 1].size(); j++)
            coeff[i][j + 1] += 2 * coeff[i - 1][j];
        for (int j = 0; j < coeff[i - 2].size(); j++)
            coeff[i][j] -= coeff[i - 2][j];
    }
    return coeff;
}

bool solve() {
    int n;
    cin >> n;

    if (!n)
        return 0;

    static vector<vector<long long>> coeff = prepare();

    for (int p = coeff[n].size() - 1; p >= 0; p--) {
        if (!coeff[n][p])
            continue;
        if (coeff[n][p] > 0 && p < coeff[n].size() - 1)
            cout << "+";
        if (coeff[n][p] < 0)
            cout << "-";
        if (abs(coeff[n][p]) > 1 || !p)
            cout << abs(coeff[n][p]);
        if (p) {
            cout << "Cos";
            if (p > 1)
                cout << "^" << p;
            cout << "(A)";
        }
    }
    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}