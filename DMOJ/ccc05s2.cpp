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

    int w, h;
    cin >> w >> h;

    int x = 0, y = 0;
    while (1) {
        int dx, dy;
        cin >> dx >> dy;

        if (!dx && !dy)
            break;

        x = clamp(x + dx, 0, w);
        y = clamp(y + dy, 0, h);

        cout << x << " " << y << "\n";
    }
}