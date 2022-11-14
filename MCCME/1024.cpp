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

    int h, w, mineCount;
    cin >> h >> w >> mineCount;

    vector<string> a(h, string(w, '0'));

    for (int i = 0; i < mineCount; i++) {
        int y, x;
        cin >> y >> x;
        y--;
        x--;

        a[y][x] = '*';

        static vector<int> dy = { -1, -1, -1, 0, 1, 1, 1, 0 };
        static vector<int> dx = { -1, 0, 1, 1, 1, 0, -1, -1 };

        for (int d = 0; d < dy.size(); d++) {
            int ty = y + dy[d];
            int tx = x + dx[d];

            if (0 <= ty && ty < h && 0 <= tx && tx < w && a[ty][tx] != '*')
                a[ty][tx]++;
        }
    }

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            if (a[y][x] == '*' || a[y][x] > '0')
                cout << a[y][x];
            else
                cout << ".";
        }
        cout << "\n";
    }
}