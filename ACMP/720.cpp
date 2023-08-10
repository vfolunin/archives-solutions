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

    double radius, size;
    cin >> radius >> size;

    int res = 0;
    for (int y = radius / size; y > 0; y--)
        res += sqrt(radius * radius - y * y * size * size) / size;

    cout << 4 * res;
}