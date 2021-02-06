#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int width, int height, vector<vector<int>> &scent) {
    int x, y;
    char c;
    if (!(cin >> x >> y >> c))
        return 0;

    static vector<int> dx = { 0, 1, 0, -1 };
    static vector<int> dy = { 1, 0, -1, 0 };
    static string s = "NESW";

    string commands;
    cin >> commands;

    int d = s.find(c);

    for (char command : commands) {
        if (command == 'R') {
            d = (d + 1) % 4;
        } else if (command == 'L') {
            d = (d + 3) % 4;
        } else {
            int tx = x + dx[d];
            int ty = y + dy[d];
            if (tx < 0 || tx > width || ty < 0 || ty > height) {
                if (scent[y][x])
                    continue;
                scent[y][x] = 1;
                cout << x << " " << y << " " << s[d] << " LOST\n";
                return 1;
            }
            x = tx;
            y = ty;
        }
    }

    cout << x << " " << y << " " << s[d] << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int width, height;
    cin >> width >> height;

    vector<vector<int>> scent(height + 1, vector<int>(width + 1));

    while (solve(width, height, scent));
}