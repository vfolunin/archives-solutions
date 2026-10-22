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

    int height, width;
    cin >> height >> width;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int value;
            cin >> value;

            if (value && (!y || y + 1 == height || !x || x + 1 == width)) {
                cout << 2;
                return 0;
            }
        }
    }

    cout << 4;
}