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

    int n;
    cin >> n;

    int resX = 0, resY = 0;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;

        if (resX * resX + resY * resY < x * x + y * y) {
            resX = x;
            resY = y;
        }
    }

    cout << resX << " " << resY;
}