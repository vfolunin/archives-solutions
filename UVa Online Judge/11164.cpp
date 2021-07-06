#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    double a, b, c;
    cin >> a >> b >> c;

    if (a < 0)
        return 0;

    cout << "Set " << test << ":\n";
    double den = b * b - a * c;
    if (den <= 1e-9) {
        cout << "Poor King!\n";
    } else {
        double s1 = a * c * (a + b) / den;
        double s2 = a * c * (b + c) / den;
        cout.precision(4);
        cout << fixed << s1 + s2 << "\n";
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}