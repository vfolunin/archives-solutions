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

    double t1, t2;
    cin >> t1 >> t2;

    double v = 100 / (t2 - t1);
    double t = t1 - 75 / v;

    cout << fixed << 50 / t - v;
}