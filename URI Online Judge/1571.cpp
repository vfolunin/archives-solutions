#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    double size;
    if (!(cin >> size))
        return 0;

    static vector<double> values = {
        1.0352761804100830, 0.8164965809277260, 0.6764079149030510, 0.6339745962155614,
        0.5545791573148570, 0.5257834230632085, 0.4766271094389717
    };

    cout.precision(10);
    for (double value : values)
        cout << fixed << value * size << " ";
    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}