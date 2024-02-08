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

    cout << fixed << 2 * acos(-1) * radius << " " << acos(-1) * radius * radius;
}