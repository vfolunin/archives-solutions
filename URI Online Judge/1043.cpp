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

    double a, b, c;
    cin >> a >> b >> c;

    double m = max(a, max(b, c));

    cout.precision(1);
    if (m + m < a + b + c)
        cout << "Perimetro = " << fixed << a + b + c << "\n";
    else
        cout << "Area = " << fixed << (a + b) * c / 2 << "\n";
}