#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int area;
    cin >> area;

    if (!area)
        return 0;

    int resH = 1, resW = area;
    for (int h = 2; h * h <= area; h++) {
        if (area % h)
            continue;
        int w = area / h;

        if (resH + resW > h + w) {
            resH = h;
            resW = w;
        }
    }

    cout << "Minimum perimeter is " << 2 * (resH + resW) << " with dimensions " << resH << " x " << resW << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}