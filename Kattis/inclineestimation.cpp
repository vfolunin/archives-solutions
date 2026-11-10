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

    double width, height;
    cin >> width >> height;

    cout << (atan2(height, width) < acos(-1) / 180 * 15 ? "Yes" : "No");
}