#include <iostream>
#include <iomanip>
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
            if ((y + x) % 2)
                cout << setw(4) << 0;
            else
                cout << setw(4) << (y * w + x) / 2 + 1;
        }
        cout << "\n";
    }
}