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

    vector<vector<int>> a(h, vector<int>(w));
    for (int y = 0; y < h; y++)
        for (int x = 0; x < w; x++)
            cin >> a[y][x];

    vector<int> dy = { -1, -1, -1, 0, 1, 1, 1, 0 };
    vector<int> dx = { -1, 0, 1, 1, 1, 0, -1, -1 };
    vector<string> res(h, string(w, '.'));

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            if (!a[y][x])
                continue;

            bool mine = 1;
            for (int d = 0; d < dy.size(); d++) {
                int ty = y + dy[d];
                int tx = x + dx[d];

                mine &= ty < 0 || ty >= h || tx < 0 || tx >= w || a[ty][tx];
            }

            res[y][x] = mine ? '*' : '0';
        }
    }

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            if (res[y][x] != '0')
                continue;

            for (int d = 0; d < dy.size(); d++) {
                int ty = y + dy[d];
                int tx = x + dx[d];

                res[y][x] += 0 <= ty && ty < h && 0 <= tx && tx < w && res[ty][tx] == '*';
            }

            if (res[y][x] == '0') {
                cout << "No solution";
                return 0;
            }
        }
    }
    
    for (string &s : res)
        cout << s << "\n";
}