#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int w, h, commandCount;
    if (!(cin >> w >> h >> commandCount))
        return 0;

    int x = 0, y = 0, imagX = 0, imagY = 0;

    for (int i = 0; i < commandCount; i++) {
        char direction;
        int distance;
        cin >> direction >> distance;

        if (direction == 'u') {
            y = min(y + distance, h - 1);
            imagY += distance;
        } else if (direction == 'd') {
            y = max(y - distance, 0);
            imagY -= distance;
        } else if (direction == 'r') {
            x = min(x + distance, w - 1);
            imagX += distance;
        } else {
            x = max(x - distance, 0);
            imagX -= distance;
        }
    }

    cout << "Robot thinks " << imagX << " " << imagY << "\n";
    cout << "Actually at " << x << " " << y << "\n\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}