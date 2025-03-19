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

    vector<string> a(h);
    for (string &s : a)
        cin >> s;

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            if (a[y][x] == '.')
                continue;

            static vector<int> dy = { -1, 0, 1, 1 };
            static vector<int> dx = { 1, 1, 1, 0 };

            for (int d = 0; d < dy.size(); d++) {
                int count = 0;

                for (int step = 0; step < 5; step++) {
                    int ty = y + dy[d] * step;
                    int tx = x + dx[d] * step;
                    if (ty < 0 || ty >= h || tx < 0 || tx >= w || a[ty][tx] != a[y][x])
                        break;
                    count++;
                }

                if (count == 5) {
                    cout << "Yes";
                    return 0;
                }
            }
        }
    }

    cout << "No";
}