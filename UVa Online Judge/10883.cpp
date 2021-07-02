#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<double> getLogF() {
    vector<double> res = { 0 };
    for (int i = 1; i <= 500000; i++)
        res.push_back(res[i - 1] + log(i));
    return res;
}

double logC(int n, int k) {
    static vector<double> logF = getLogF();
    return logF[n] - logF[n - k] - logF[k];
}

void solve(int test) {
    int n;
    cin >> n;

    double res = 0, den = (n - 1) * log(2);
    for (int i = 0; i < n; i++) {
        double x;
        cin >> x;
        res += x * exp(logC(n - 1, i) - den);
    }

    cout.precision(3);
    cout << "Case #" << test << ": " << fixed << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}