#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    float a, b;
    double c, d;
    cin >> a >> b >> c >> d;

    cout << fixed;
    cout << "A = " << a << ", B = " << b << "\n";
    cout << "C = " << c << ", D = " << d << "\n";

    for (int i = 1; i <= 3; i++) {
        cout << setprecision(i);
        cout << "A = " << a << ", B = " << b << "\n";
        cout << "C = " << c << ", D = " << d << "\n";
    }

    cout << scientific << uppercase;
    cout << "A = " << a << ", B = " << b << "\n";
    cout << "C = " << c << ", D = " << d << "\n";

    cout << fixed << setprecision(0);
    cout << "A = " << a << ", B = " << b << "\n";
    cout << "C = " << c << ", D = " << d << "\n";
}