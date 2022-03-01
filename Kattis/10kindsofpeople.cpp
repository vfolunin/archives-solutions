#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct DSU {
    vector<int> id;

    DSU(int n) {
        for (int i = 0; i < n; i++)
            id.push_back(i);
    }

    int find(int i) {
        return id[i] == i ? i : id[i] = find(id[i]);
    }

    bool connected(int i, int j) {
        return find(i) == find(j);
    }

    void merge(int i, int j) {
        int r1 = find(i), r2 = find(j);
        if (r1 == r2)
            return;
        if (rand() % 2)
            id[r1] = r2;
        else
            id[r2] = r1;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int h, w;
    cin >> h >> w;

    vector<string> a(h);
    for (string &row : a)
        cin >> row;

    vector<DSU> dsu = { DSU(h * w), DSU(h * w) };

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            static int dy[] = { -1, 0, 1, 0 };
            static int dx[] = { 0, 1, 0, -1 };

            for (int d = 0; d < 4; d++) {
                int ty = y + dy[d];
                int tx = x + dx[d];

                if (0 <= ty && ty < h && 0 <= tx && tx < w && a[y][x] == a[ty][tx])
                    dsu[a[y][x] - '0'].merge(y * w + x, ty * w + tx);
            }
        }
    }

    int queryCount;
    cin >> queryCount;

    for (int i = 0; i < queryCount; i++) {
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;
        y1--;
        x1--;
        y2--;
        x2--;

        if (a[y1][x1] == '0' && a[y2][x2] == '0' && dsu[0].connected(y1 * w + x1, y2 * w + x2))
            cout << "binary\n";
        else if (a[y1][x1] == '1' && a[y2][x2] == '1' && dsu[1].connected(y1 * w + x1, y2 * w + x2))
            cout << "decimal\n";
        else
            cout << "neither\n";
    }
}