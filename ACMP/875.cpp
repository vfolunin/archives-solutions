#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int getNeighborCount(vector<string> &a, int y, int x) {
    static vector<int> dy = { -1, -1, -1, 0, 1, 1, 1, 0 };
    static vector<int> dx = { -1, 0, 1, 1, 1, 0, -1, -1 };
    int h = a.size(), w = a[0].size(), neighborCount = 0;
    
    for (int d = 0; d < dy.size(); d++) {
        int ty = (y + dy[d] + h) % h;
        int tx = (x + dx[d] + w) % w;

        neighborCount += a[ty][tx] == '*';
    }

    return neighborCount;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int h, w, iterationCount;
    cin >> h >> w >> iterationCount;

    vector<string> a(h);
    for (string &row : a)
        cin >> row;

    for (int i = 0; i < iterationCount; i++) {
        vector<string> b = a;
        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                int neighborCount = getNeighborCount(a, y, x);
                if (neighborCount < 2 || neighborCount > 3)
                    b[y][x] = '.';
                else if (neighborCount == 3)
                    b[y][x] = '*';
            }
        }
        a.swap(b);
    }

    for (string &row : a)
        cout << row << "\n";
}