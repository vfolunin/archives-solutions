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

    double minValue = 1e100;

    for (double value; cin >> value; )
        minValue = min(minValue, value);

    cout.precision(2);
    cout << fixed << minValue;
}