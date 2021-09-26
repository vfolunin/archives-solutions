#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<long double> getLogF() {
    vector<long double> logF(4e5);
    for (int i = 2; i < logF.size(); i++)
        logF[i] = logF[i - 1] + log(i);
    return logF;
}

long double logC(int n, int m) {
    static vector<long double> logF = getLogF();
    return logF[n] - logF[m] - logF[n - m];
}

bool solve(int test) {
    int n;
    long double p;

    if (!(cin >> n >> p))
        return 0;

    long double logP = log(p);
    long double logQ = log(1 - p);
    long double res = 0;

    for (int i = 1; i <= n; i++) {
        res += i * exp(logC(2 * n - i, n) + (n + 1) * logP + (n - i) * logQ);
        res += i * exp(logC(2 * n - i, n) + (n + 1) * logQ + (n - i) * logP);
    }

    cout << "Case " << test << ": " << fixed << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}