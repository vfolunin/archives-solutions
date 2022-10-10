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
            cout.width(3);
            if (y % 2 == 0)
                cout << y * w + x;
            else
                cout << (y + 1) * w - 1 - x;
        }
        cout << "\n";
    }
}