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

    int type;
    cin >> type;

    double res = 0;
    if (type == 1) {
        for (double num = 1, den = 2; num <= 19; num += 2, den += 2)
            res += num / den;
    } else if (type == 2) {
        for (double num = 1, den = 2; num <= 10; num++, den++)
            res += num / den;
    } else if (type == 3) {
        for (double num = 2, den = 3; num <= 20; num += 2, den += 2)
            res += num / den;
    } else if (type == 4) {
        for (double num = 1, den = 1; num <= 10; num++, den += 2)
            res += num / den;
    } else if (type == 5) {
        for (double num = 1, den = 2; num <= 10; num++, den += 3)
            res += num / den;
    } else {
        for (double num = 1, den = 3; num <= 19; num += 2, den += 3)
            res += num / den;
    }

    cout.precision(2);
    cout << fixed << res;
}