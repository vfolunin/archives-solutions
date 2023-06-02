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

    int size, resX, resY;
    cin >> size >> resX >> resY;

    for (int i = 1; i < size; i++) {
        int x, y;
        cin >> x >> y;

        if (resY > y || resY == y && resX < x) {
            resX = x;
            resY = y;
        }
    }

    cout << resX << " " << resY;
}