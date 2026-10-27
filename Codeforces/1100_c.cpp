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

    double circleCount, innerRadius;
    cin >> circleCount >> innerRadius;

    double factor = sin(acos(-1) / circleCount);
    double outerRadius = innerRadius * factor / (1 - factor);

    cout << fixed << outerRadius;
}