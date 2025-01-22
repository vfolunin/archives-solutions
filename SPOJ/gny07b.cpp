#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    double value;
    string unit;
    cin >> value >> unit;

    cout.precision(4);
    if (unit == "kg")
        cout << test << " " << fixed << value * 2.2046 << " lb\n";
    else if (unit == "lb")
        cout << test << " " << fixed << value * 0.4536 << " kg\n";
    else if (unit == "l")
        cout << test << " " << fixed << value * 0.2642 << " g\n";
    else
        cout << test << " " << fixed << value * 3.7854 << " l\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}