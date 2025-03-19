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

    double x;
    cin >> x;

    cout.precision(4);
    cout << fixed << (2 * x - 1 / x) / 3;
}