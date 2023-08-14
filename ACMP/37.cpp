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
    double coeff;
    cin >> pointCount >> coeff;

    for (int i = 0; i < pointCount; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        if (hypot(x1, y1) * coeff + 1e-9 < hypot(x2, y2)) {
            cout << "No";
            return 0;
        }
    }

    cout << "Yes";
}