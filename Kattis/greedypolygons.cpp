#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int sideCount, sideLength, distance, expansionCount;
    cin >> sideCount >> sideLength >> distance >> expansionCount;

    int radius = distance * expansionCount;

    double area = sideCount * sideLength * sideLength / (4 * tan(acos(-1) / sideCount));
    area += sideCount * sideLength * radius;
    area += acos(-1) * radius * radius;

    cout << fixed << area << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}