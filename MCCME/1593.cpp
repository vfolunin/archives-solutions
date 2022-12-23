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

    int h, w;
    cin >> h >> w;

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            if (y % 2 == 0)
                cout << y * w + x + 1 << " ";
            else
                cout << (y + 1) * w - x << " ";
        }
        cout << "\n";
    }
}