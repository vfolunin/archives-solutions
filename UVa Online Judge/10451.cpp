#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    int n;
    double area;
    cin >> n >> area;

    if (n < 3)
        return 0;

    static const double PI = acos(-1);

    double side = sqrt(area * 4 * tan(PI / n) / n);

    double innerR = side / (2 * tan(PI / n));
    double innerArea = PI * innerR * innerR;

    double outerR = side / (2 * sin(PI / n));
    double outerArea = PI * outerR * outerR;

    cout << "Case " << test << ": ";
    cout.precision(5);
    cout << fixed << outerArea - area << " " << area - innerArea << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}