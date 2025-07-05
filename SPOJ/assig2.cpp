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

void solve(int test) {
    double c, d;
    cin >> c >> d;

    cout.precision(2);
    cout << "Case " << test << ": " << fixed << toC(toF(c) + d) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 1; test <= testCount; test++)
        solve(test);
}