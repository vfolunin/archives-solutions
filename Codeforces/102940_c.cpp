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
 
    double volume;
    cin >> volume;

    double l = 0, r = 1e9;
    for (int i = 0; i < 300; i++) {
        double m = (l + r) / 2;
        if (m * m * m * 153 < volume)
            l = m;
        else
            r = m;
    }

    cout.precision(10);
    cout << fixed << l;
}