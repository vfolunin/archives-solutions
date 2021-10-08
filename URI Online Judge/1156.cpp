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
    for (double num = 1, den = 1; num <= 39; num += 2, den *= 2)
        res += num / den;

    cout.precision(2);
    cout << fixed << res << "\n";
}