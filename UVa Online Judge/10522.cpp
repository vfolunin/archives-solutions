#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    double a, b, c;
    cin >> a >> b >> c;

    double num = pow(a * b * c, 2);
    double den = 2 * num * (a * a + b * b + c * c) - (pow(a * b, 4) + pow(a * c, 4) + pow(b * c, 4));
    
    if (den <= 0) {
        cout << "These are invalid inputs!\n";
        return 0;
    }

    cout.precision(3);
    cout << fixed << num / sqrt(den) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    while (n)
        n -= !solve();
}