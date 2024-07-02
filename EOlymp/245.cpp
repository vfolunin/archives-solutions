#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int numLimit, denLimit;
    cin >> numLimit >> denLimit;

    const double PI = acos(-1);

    double bestDiff = 1e9;
    int bestNum, bestDen;

    for (int num = 1; num <= numLimit; num++) {
        for (int den = 1; den <= denLimit; den++) {
            if (gcd(num, den) > 1)
                continue;

            double diff = abs(PI - (double)num / den);
            if (bestDiff > diff) {
                bestDiff = diff;
                bestNum = num;
                bestDen = den;
            }
        }
    }

    cout << bestNum << " " << bestDen;
}