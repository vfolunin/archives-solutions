#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<double> getLogF() {
    vector<double> logF(100001);
    for (int i = 2; i < logF.size(); i++)
        logF[i] += logF[i - 1] + log(i);
    return logF;
}

double logC(int n, int k) {
    static vector<double> logF = getLogF();
    return logF[n] - (logF[n - k] + logF[k]);
}

void solve() {
    int n;
    cin >> n;

    double logRes = logC(n - 2, n / 2 - 1) - (n - 2) * log(2);

    cout.precision(4);
    cout << fixed << 1 - exp(logRes) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}