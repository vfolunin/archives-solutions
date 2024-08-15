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

    int l, r, aDeg, bDeg;
    cin >> l >> r >> aDeg >> bDeg;

    int resA = 1e9, resB = 1e9;
    for (int a = bDeg; a <= r; a++) {
        for (int b = aDeg; a + b <= r; b++) {
            if (l <= a + b && a * aDeg == b * bDeg && resA + resB > a + b) {
                resA = a;
                resB = b;
            }
        }
    }

    cout << resA + resB << " " << resA << " " << resB;
}