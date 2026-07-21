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

    int sideCount, side;
    cin >> sideCount >> side;

    double radius = side / (2 * sin(acos(-1) / sideCount));

    cout << fixed << acos(-1) * radius * radius;
}