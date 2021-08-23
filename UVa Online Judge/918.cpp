#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <complex>
using namespace std;

const double EPS = 1e-9;

void solve(int test) {
    string symbols;
    double y1, y2, dy, x1, x2, dx;
    cin >> symbols >> y1 >> y2 >> dy >> x1 >> x2 >> dx;
    symbols.back() = ' ';

    if (test)
        cout << "\n";

    for (double y = y1; y <= y2 + EPS; y += dy) {
        for (double x = x1; x <= x2 + EPS; x += dx) {
            complex<double> z, c(x, y);
            int i;
            for (i = 0; abs(z) <= 2 + EPS && i + 1 < symbols.size(); i++)
                z = z * z + c;
            cout << symbols[i];
        }
        cout << "\n";
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve(i);
}