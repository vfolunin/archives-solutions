#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int digitCount(int n) {
    return n < 10 ? 1 : 1 + digitCount(n / 10);
}

double log2(double x) {
    return log(x) / log(2);
}

bool solve() {
    int x;
    if (!(cin >> x))
        return 0;

    for (int len = digitCount(x) + 1; 1; len++) {
        int a = log2(x) + len * log2(10);
        int b = log2(x + 1) + len * log2(10);
        if (a < b) {
            cout << b << "\n";
            return 1;
        }
    }

    return -1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}