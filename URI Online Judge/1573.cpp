#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int a, b, c;
    cin >> a >> b >> c;

    if (!a && !b && !c)
        return 0;

    cout << (int)pow(a * b * c, 1.0 / 3) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}