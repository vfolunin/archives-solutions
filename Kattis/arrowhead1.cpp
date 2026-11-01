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

    double l1, b1, l2, b2, x2;
    cin >> l1 >> b1 >> l2 >> b2 >> x2;

    double l3 = x2 + l2 - l1;
    double b3 = b2 * (1 - l3 / l2);

    cout << fixed << (l1 * b1 + l3 * (b2 + b3)) / 2;
}