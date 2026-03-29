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

    double x, y;
    cin >> x >> y;

    if (y == 1) {
        if (x == 0)
            cout << "ALL GOOD";
        else
            cout << "IMPOSSIBLE";
    } else {
        cout << fixed << x / (1 - y);
    }
}