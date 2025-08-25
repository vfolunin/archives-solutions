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

    double res = 0;
    for (int i = 0; i < size; i++) {
        double angle, r1, r2;
        cin >> angle >> r1 >> r2;

        res += (angle / 180 * acos(-1) / 2) * (r2 * r2 - r1 * r1);
    }

    cout << fixed << res;
}