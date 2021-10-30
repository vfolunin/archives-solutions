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

    double a = 234.345, b = 45.698;

    cout << fixed;
    cout << setprecision(6) << a << " - " << b << "\n";
    cout << setprecision(0) << a << " - " << b << "\n";
    cout << setprecision(1) << a << " - " << b << "\n";
    cout << setprecision(2) << a << " - " << b << "\n";
    cout << setprecision(3) << a << " - " << b << "\n";

    cout << scientific << setprecision(6);
    cout << a << " - " << b << "\n";
    cout << uppercase << a << " - " << b << "\n";

    cout << fixed << setprecision(3);
    cout << a << " - " << b << "\n";
    cout << a << " - " << b << "\n";
}