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

    int size;
    cin >> size;

    int res;
    double resDist = -1;

    for (int i = 0; i < size; i++) {
        int radius, x, y, z;
        cin >> radius >> x >> y >> z;

        double dist = hypot(hypot(x, y) + radius, z);
        if (resDist + 1e-9 < dist) {
            resDist = dist;
            res = i + 1;
        }
    }

    cout << res;
}