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

    int a, b, c;
    cin >> a >> b >> c;

    int d = b * b - 4 * a * c;

    if (d > 0) {
        int x1 = (-b - sqrt(d)) / (2 * a);
        int x2 = (-b + sqrt(d)) / (2 * a);
        if (x1 > x2)
            swap(x1, x2);
        cout << "Two roots: " << fixed << x1 << " " << x2;
    } else if (d == 0) {
        cout << "One root: " << fixed << -b / (2 * a);
    } else {
        cout << "No roots";
    }
}