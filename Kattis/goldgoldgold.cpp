#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    double num1, den1, num2, den2;
    cin >> num1 >> den1 >> num2 >> den2;

    if (num1 == den1) {
        cout << "1\n";
        return;
    }

    num1 = den1 - num1;
    num2 = den2 - num2;

    cout << (int)ceil(log(num2 / den2) / log(num1 / den1)) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}