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

    double a, b;
    cin >> a >> b;

    double radius = a + b + sqrt(2 * a * b);

    cout << fixed << acos(-1) * radius * radius;
}