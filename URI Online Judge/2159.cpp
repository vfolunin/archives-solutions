#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    double n;
    cin >> n;

    double l = n / log(n);
    double r = 1.25506 * l;

    cout.precision(1);
    cout << fixed << l << " " << r << "\n";
}