#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

double binet(int n) {
    static const double s5 = sqrt(5);
    return (pow((1 + s5) / 2, n) - pow((1 - s5) / 2, n)) / s5;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    cout.precision(1);
    cout << fixed << binet(n) << "\n";
}