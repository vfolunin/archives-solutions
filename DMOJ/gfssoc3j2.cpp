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
    double amount;
    cin >> size >> amount;

    for (int i = 0; i < size; i++) {
        double value;
        cin >> value;

        amount -= value;
    }

    if (amount >= -1e-9) {
        cout.precision(2);
        cout << fixed << abs(amount);
    } else {
        cout << "Fardin's broke";
    }
}