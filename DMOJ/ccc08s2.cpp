#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    long long radius;
    cin >> radius;
    if (!radius)
        return 0;

    long long res = 0;
    for (int y = radius, x = 0; y; y--) {
        while (y * y + (x + 1) * (x + 1) <= radius * radius)
            x++;
        res += x + 1;
    }

    cout << res * 4 + 1 << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}