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

    int typeCount;
    cin >> typeCount;
    typeCount--;

    vector<int> sheetCount(typeCount);
    vector<double> side(typeCount);

    double a = pow(2, -1.25), b = pow(2, -0.75);
    for (int i = 0; i < typeCount; i++) {
        cin >> sheetCount[i];
        side[i] = b;
        swap(a, b);
        a /= 2;
    }

    int sheetsNeeded = 2;
    double res = 0;
    for (int i = 0; i < typeCount; i++) {
        res += (sheetsNeeded + 1) / 2 * side[i];
        sheetsNeeded = max(sheetsNeeded - sheetCount[i], 0) * 2;
    }

    if (sheetsNeeded)
        cout << "impossible";
    else
        cout << fixed << res;
}