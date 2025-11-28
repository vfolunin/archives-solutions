#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int vx, vy;
    if (!(cin >> vx >> vy))
        return 0;

    int x = 50, y = 25;
    while (0 < x && x < 100 && 0 < y && y < 50) {
        x += vx;
        y += vy;
    }

    cout << x << "," << y << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}