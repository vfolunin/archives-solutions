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

    double area, radius;
    cin >> area >> radius;

    cout.precision(2);
    cout << fixed << sqrt(radius * radius - area / acos(-1.0));
}