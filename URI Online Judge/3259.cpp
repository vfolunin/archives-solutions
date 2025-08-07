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

    double factor;
    cin >> factor;

    bool found = 0;
    for (int size = 1; size <= 8; size++) {
        for (int digit = 1; digit <= 9; digit++) {
            int value = (pow(10, size) - 1) / (10 - factor) * digit + 1e-9;

            string s = to_string(value);
            if (s.size() != size || s[0] - '0' != digit)
                continue;
            double shiftedValue = stoi(s.substr(1) + s.substr(0, 1));

            if (abs(shiftedValue / value - factor) < 1e-9) {
                cout << value << "\n";
                found = 1;
            }
        }
    }

    if (!found)
        cout << "No solution\n";
}