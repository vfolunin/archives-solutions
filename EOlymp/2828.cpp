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

    int size;
    cin >> size;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    vector<int> coeff(size + 1);
    for (int mask = 0; mask < (1 << a.size()); mask++) {
        int power = 0, value = 1;
        for (int bit = 0; bit < a.size(); bit++) {
            if (mask & (1 << bit))
                value *= a[bit];
            else
                power++;
        }
        coeff[power] += value;
    }

    for (int power = coeff.size() - 1; power >= 0; power--) {
        if (!coeff[power])
            continue;

        if (coeff[power] < 0)
            cout << "-";
        else if (power < coeff.size() - 1)
            cout << "+";

        if (abs(coeff[power]) != 1 || !power) {
            cout << abs(coeff[power]);
            if (power)
                cout << "*";
        }

        if (power) {
            cout << "X";
            if (power > 1)
                cout << "^" << power;
        }
    }
}