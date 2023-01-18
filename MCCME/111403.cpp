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

    double value;
    cin >> value;

    double l = 0, r = value;
    for (int i = 0; i < 100; i++) {
        double m = (l + r) / 2;
        if (m * m * m * m + m <= value)
            l = m;
        else
            r = m;
    }

    cout << fixed << l * l;
}