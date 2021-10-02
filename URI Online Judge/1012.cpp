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

    const double PI = 3.14159;

    cout.precision(3);
    cout << fixed;
    cout << "TRIANGULO: " << a * c / 2 << "\n";
    cout << "CIRCULO: " << PI * c * c << "\n";
    cout << "TRAPEZIO: " << (a + b) * c / 2 << "\n";
    cout << "QUADRADO: " << b * b << "\n";
    cout << "RETANGULO: " << a * b << "\n";
}