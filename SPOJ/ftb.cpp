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

    int r, c, h, w;
    cin >> r >> c >> h >> w;

    for (int y = 0; y < r * h; y++) {
        for (int x = 0; x < c * w; x++)
            cout << (((y / h) + (x / w)) % 2 ? "." : "X");
        cout << "\n";
    }
}