#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<double> prepare() {
    vector<double> logAcos(1e6 + 1);
    logAcos[0] = log10(3);
    for (int i = 1; i < logAcos.size(); i++) {
        logAcos[i] = logAcos[i - 1];
        logAcos[i] += log10(2 * i - 1);
        logAcos[i] -= log10(2 * i);
        logAcos[i] -= log10(4);
        logAcos[i] += log10(2 * i - 1);
        logAcos[i] -= log10(2 * i + 1);
    }
    return logAcos;
}

bool solve() {
    int n;
    cin >> n;

    if (n == -1)
        return 0;

    static vector<double> logAcos = prepare();

    int l = 0, r = logAcos.size();
    while (l + 1 < r) {
        int m = l + (r - l) / 2;
        if (logAcos[m] < -n)
            r = m;
        else
            l = m;
    }

    cout << r << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}