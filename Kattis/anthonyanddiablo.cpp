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

    double area, len;
    cin >> area >> len;

    double radius = sqrt(area / acos(-1));
    double perimeter = 2 * acos(-1) * radius;

    if (perimeter <= len + 1e-9)
        cout << "Diablo is happy!";
    else
        cout << "Need more materials!";
}