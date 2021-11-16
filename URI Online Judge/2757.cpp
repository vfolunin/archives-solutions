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

    int a, b, c;
    cin >> a >> b >> c;

    cout << "A = " << a << ", B = " << b << ", C = " << c << "\n";
    cout << "A = " << setw(10) << a << ", B = " << setw(10) << b << ", C = " << setw(10) << c << "\n";
    cout << internal << setfill('0');
    cout << "A = " << setw(10) << a << ", B = " << setw(10) << b << ", C = " << setw(10) << c << "\n";
    cout << left << setfill(' ');
    cout << "A = " << setw(10) << a << ", B = " << setw(10) << b << ", C = " << setw(10) << c << "\n";
}