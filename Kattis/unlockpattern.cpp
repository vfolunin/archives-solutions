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

    vector<int> ys(9), xs(9);
    for (int y = 0; y < 3; y++) {
        for (int x = 0; x < 3; x++) {
            int i;
            cin >> i;
            ys[i - 1] = y;
            xs[i - 1] = x;
        }
    }

    double len = 0;
    for (int i = 0; i < 8; i++)
        len += hypot(xs[i + 1] - xs[i], ys[i + 1] - ys[i]);

    cout << fixed << len;
}