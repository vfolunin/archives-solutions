#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int radius;
    cin >> radius;

    int res = 0;
    for (int y = radius - 1, x = 0; y; y--) {
        while (y * y + (x + 1) * (x + 1) <= radius * radius)
            x++;
        res += x;
    }

    cout << res * 4;
}