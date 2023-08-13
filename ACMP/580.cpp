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

    double a, b, c, radius;
    cin >> a >> b >> c >> radius;

    double p = (a + b + c) / 2;
    
    cout << (radius <= sqrt((p - a) * (p - b) * (p - c) / p) + 1e-9 ? "YES" : "NO");
}