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

    int n, a;
    cin >> n >> a;

    double r1 = a / (2 * tan(acos(-1) / n));
    double r2 = a / (2 * sin(acos(-1) / n));

    cout << (r2 - r1 < 1 ? "YES" : "NO");
}