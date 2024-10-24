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

    double num = 0, den = 0;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        if (value < 0 && value % 2) {
            num += value;
            den++;
        }
    }

    if (den) {
        cout.precision(2);
        cout << fixed << num / den;
    } else {
        cout << "NO";
    }
}