#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long cost(long long price, long long tax) {
    return (price * tax + 5000) / 10000 * 10000;
}

void solve() {
    int categoryCount, purchaseCount;
    cin >> categoryCount >> purchaseCount;

    map<string, long long> tax1, tax2, tax3;

    for (int i = 0; i < categoryCount; i++) {
        string category;
        char c;
        double p1, p2, p3;
        cin >> category >> p1 >> c >> p2 >> c >> p3 >> c;

        tax1[category] = roundl(p1 * 100);
        tax2[category] = roundl(p2 * 100);
        tax3[category] = roundl(p3 * 100);
    }

    long long costA = 0, costB = 0;

    for (int i = 0; i < purchaseCount; i++) {
        string category;
        char c;
        double m;
        cin >> category >> c >> m;

        costA += cost(roundl(m * 100), tax1[category]);
        costA += cost(roundl(m * 100), tax2[category]);
        costB += cost(roundl(m * 100), tax3[category]);
    }

    cout.precision(2);
    cout << fixed << (costB - costA) / 1000000.0 << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}