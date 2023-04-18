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

    double num1 = e * d - b * f;
    double num2 = a * f - e * c;
    double den = a * d - b * c;

    cout << fixed << num1 / den << " " << num2 / den;
}