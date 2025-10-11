#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool hasEvenDigits(int n) {
    for (; n; n /= 10)
        if (n % 2)
            return 0;
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int d;
    cin >> d;

    for (int i = d; i <= 1e9; i += d)
        if (i >= 12141 &&
            hasEvenDigits(i / 100000) &&
            i % 100000 / 1000 == 12 &&
            i % 1000 / 100 % 2 &&
            i % 100 / 10 == 4 &&
            i % 10 % 2)
            cout << i << " " << i / d << "\n";
}