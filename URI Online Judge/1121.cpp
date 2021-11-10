#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int height, width, n;
    cin >> height >> width >> n;

    if (!height && !width && !n)
        return 0;

    vector<string> a(height);
    int robotY, robotX, robotD;
    for (int y = 0; y < height; y++) {
        cin >> a[y];
        for (int x = 0; x < width; x++) {
            if (isalpha(a[y][x])) {
                robotY = y;
                robotX = x;
                robotD = string("NLSO").find(a[robotY][robotX]);
            }
        }
    }

    string commands;
    cin >> commands;

    static int dy[] = { -1, 0, 1, 0 };
    static int dx[] = { 0, 1, 0, -1 };

    int res = 0;
    for (char command : commands) {
        if (command == 'D') {
            robotD = (robotD + 1) % 4;
        } else if (command == 'E') {
            robotD = (robotD + 3) % 4;
        } else {
            int ty = robotY + dy[robotD];
            int tx = robotX + dx[robotD];
            if (0 <= ty && ty < height && 0 <= tx && tx < width && a[ty][tx] != '#') {
                robotY = ty;
                robotX = tx;
                if (a[robotY][robotX] == '*') {
                    a[robotY][robotX] = '.';
                    res++;
                }
            }
        }
    }

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}