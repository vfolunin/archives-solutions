#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int gearCount;
    cin >> gearCount;

    double bestY;
    int bestGear;

    for (int i = 0; i < gearCount; i++) {
        double a, b, c;
        cin >> a >> b >> c;

        double x = b / (2 * a);
        double y = -a * x * x + b * x + c;

        if (!i || bestY < y) {
            bestY = y;
            bestGear = i;
        }
    }

    cout << bestGear + 1 << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}