#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int p, a, b, c, d, n;
    if (!(cin >> p >> a >> b >> c >> d >> n))
        return 0;

    vector<double> price;
    for (int i = 1; i <= n; i++)
        price.push_back(p * (sin(a * i + b) + cos(c * i + d) + 2));

    vector<double> minPriceR = price;
    for (int i = n - 2; i >= 0; i--)
        minPriceR[i] = min(minPriceR[i], minPriceR[i + 1]);

    double res = 0;
    for (int i = 0; i < n - 1; i++)
        res = max(res, price[i] - minPriceR[i + 1]);

    cout << fixed << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}