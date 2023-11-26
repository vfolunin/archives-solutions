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

    double maxValue = 0;

    for (double value; cin >> value; )
        maxValue = max(maxValue, value);

    cout.precision(2);
    cout << fixed << maxValue;
}