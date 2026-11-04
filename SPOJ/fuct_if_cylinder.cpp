#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

double volume(double height, double radius) {
    return height * 3.14 * radius * radius;
}

double area(double height, double radius) {
    return 2 * 3.14 * radius * (radius + height);
}

void solve() {
    double radius, height;
    cin >> radius >> height;

    cout.precision(2);
    if (radius < 1e-9)
        cout << "the radius of cylinder must be greater than 0\n";
    else if (height < 1e-9)
        cout << "the height of cylinder must be greater than 0\n";
    else
        cout << fixed << volume(height, radius) << " " << area(height, radius) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}