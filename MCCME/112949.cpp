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

    int h, w, delta;
    cin >> h >> w >> delta;

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++)
            cout << (abs(y - x) == delta) << " ";
        cout << "\n";
    }
}