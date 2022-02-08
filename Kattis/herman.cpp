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

    double radius;
    cin >> radius;

    cout << fixed << acos(-1) * radius * radius << "\n";
    cout << fixed << 2 * radius * radius << "\n";
}