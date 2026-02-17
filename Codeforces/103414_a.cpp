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

    int h, w, n;
    cin >> h >> w >> n;

    if (n <= min(h, w)) {
        cout << "Possible\n";
        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++)
                cout << (y == x && y < n ? "*" : ".");
            cout << "\n";
        }
    } else {
        cout << "Impossible";
    }
}