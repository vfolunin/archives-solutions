#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

double toC(double f) {
    return (f - 32) * 5 / 9;
}

double toF(double c) {
    return c * 9 / 5 + 32;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    double value;
    char type;
    cin >> value >> type;

    cout.precision(2);
    if (type == 'C')
        cout << fixed << toF(value) << " F";
    else
        cout << fixed << toC(value) << " C";
}