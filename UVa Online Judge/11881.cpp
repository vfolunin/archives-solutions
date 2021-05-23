#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool can(vector<double> &cf, double irr) {
    double npv = cf[0], den = 1 + irr;
    for (int i = 1; i < cf.size(); i++) {
        npv += cf[i] / den;
        den *= (1 + irr);
    }
    return npv >= 0;
}

bool solve() {
    int cashFlowCount;
    cin >> cashFlowCount;

    if (!cashFlowCount)
        return 0;

    vector<double> cashFlows(cashFlowCount + 1);
    for (double &cashFlow : cashFlows)
        cin >> cashFlow;

    double l = -1, r = 1e9;
    for (int i = 0; i < 200; i++) {
        double m = (l + r) / 2;
        if (can(cashFlows, m))
            l = m;
        else
            r = m;
    }

    cout.precision(2);
    cout << fixed << l << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}