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

    int den, count;
    cin >> den >> count;

    double res = 0;
    for (int i = 0; i < count; i++)
        res += 1.0 * (den - res) / den;

    cout.precision(9);
    cout << fixed << res;
}