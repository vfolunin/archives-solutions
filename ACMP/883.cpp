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

    int pointCount;
    cin >> pointCount;

    int width = sqrt(pointCount);

    for (int i = 0; i < pointCount; i++)
        cout << fixed << i / width * 0.01 << " " << i % width * 0.01 << "\n";
}