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

    int a, b, c;
    cin >> a >> b >> c;

    cout << a << "+" << b << "+" << c << "=" << a + b + c << "\n";
    cout << a << "*" << b << "*" << c << "=" << a * b * c << "\n";
    cout.precision(3);
    cout << "(" << a << "+" << b << "+" << c << ")/3=" << fixed << (a + b + c) / 3.0 << "\n";
}