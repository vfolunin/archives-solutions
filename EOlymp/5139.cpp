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

    double v1, v2;
    cin >> v1 >> v2;

    double t1 = v2 / (v1 + v2);

    cout.precision(4);
    cout << fixed << v1 * t1 + v2 * (1 - t1);
}