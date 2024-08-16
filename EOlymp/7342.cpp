#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

double getFactor(double h1, double w1, double h2, double w2) {
    return min(h2 / h1, w2 / w1);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    double h1, w1, h2, w2;
    cin >> h1 >> w1 >> h2 >> w2;

    double factor = max(getFactor(h1, w1, h2, w2), getFactor(h1, w1, w2, h2));

    cout.precision(3);
    cout << fixed << h1 * factor << " " << w1 * factor;
}