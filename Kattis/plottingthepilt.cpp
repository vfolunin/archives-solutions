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

    int h, w, d;
    cin >> h >> w >> d;

    vector<vector<int>> a(h, vector<int>(w));
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            cin >> a[y][x];
            a[y][x] /= d;
        }
    }

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            int delta = 0;

            static vector<int> dy = { -1, 0, 1, 0 };
            static vector<int> dx = { 0, 1, 0, -1 };

            for (int d = 0; d < dy.size(); d++) {
                int ty = y + dy[d];
                int tx = x + dx[d];
                if (0 <= ty && ty < h && 0 <= tx && tx < w)
                    delta = max(delta, a[y][x] - a[ty][tx]);
            }

            if (delta <= 0)
                cout << " ";
            else if (delta == 1)
                cout << "+";
            else if (delta == 2)
                cout << "X";
            else
                cout << "#";
        }
        cout << "\n";
    }
}