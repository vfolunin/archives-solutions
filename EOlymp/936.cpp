#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    double a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;

    double det1 = c * e - b * f;
    double det2 = a * f - c * d;
    double det = a * e - b * d;

    cout << fixed << det1 / det << "\n" << det2 / det;
}