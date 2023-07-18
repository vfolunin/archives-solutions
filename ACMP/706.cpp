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

    double d, x, y;
    cin >> d >> x >> y;

    cout << fixed << d * abs(x) / (2 * d - y);
}