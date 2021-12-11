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

    vector<int> firstNonZero(h);

    for (int y = 0; y < h; y++) {
        firstNonZero[y] = w + y;
        for (int x = 0; x < w; x++) {
            int val;
            cin >> val;
            if (val && firstNonZero[y] >= w)
                firstNonZero[y] = x;
        }
    }

    for (int y = 1; y < h; y++) {
        if (firstNonZero[y] <= firstNonZero[y - 1]) {
            cout << "N\n";
            return 0;
        }
    }

    cout << "S\n";
}