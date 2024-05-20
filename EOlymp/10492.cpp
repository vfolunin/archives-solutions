#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    double radius = 1;

    for (string op; cin >> op; ) {
        if (op == "Area") {
            cout << fixed << acos(-1) * radius * radius << "\n";
        } else if (op == "Perimeter") {
            cout << fixed << 2 * acos(-1) * radius << "\n";
        } else {
            double percent;
            cin >> percent;
            radius *= percent / 100;
        }
    }
}