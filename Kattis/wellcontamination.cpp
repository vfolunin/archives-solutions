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

    vector<string> plan(height);
    for (string &row : plan)
        cin >> row;

    vector<int> dy = { -1, 0, 1, 0 };
    vector<int> dx = { 0, 1, 0, -1 };

    int res = 0;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (plan[y][x] != 'W')
                continue;

            for (int d = 0; d < dy.size(); d++) {
                int ty = y + dy[d];
                int tx = x + dx[d];

                if (0 <= ty && ty < height && 0 <= tx && tx < width && plan[ty][tx] == 'O') {
                    res++;
                    break;
                }
            }
        }
    }

    cout << res;
}