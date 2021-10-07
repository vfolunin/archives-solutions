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

    double res = 0;
    for (int den = 1; den <= 100; den++)
        res += 1.0 / den;

    cout.precision(2);
    cout << fixed << res << "\n";
}