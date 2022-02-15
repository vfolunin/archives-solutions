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

    if (a + b == c) {
        cout << a << "+" << b << "=" << c;
    } else if (a - b == c) {
        cout << a << "-" << b << "=" << c;
    } else if (a * b == c) {
        cout << a << "*" << b << "=" << c;
    } else if (a % b == 0 && a / b == c) {
        cout << a << "/" << b << "=" << c;
    } else if (a == b + c) {
        cout << a << "=" << b << "+" << c;
    } else if (a == b - c) {
        cout << a << "=" << b << "-" << c;
    } else if (a == b * c) {
        cout << a << "=" << b << "*" << c;
    } else if (b % c == 0 && a == b / c) {
        cout << a << "=" << b << "/" << c;
    }
}