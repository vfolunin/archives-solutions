#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct DSU {
    vector<int> id;
    int ccCount;

    DSU(int n) {
        for (int i = 0; i < n; i++)
            id.push_back(i);
        ccCount = n;
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
        ccCount--;
        if (rand() % 2)
            id[r1] = r2;
        else
            id[r2] = r1;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int h, w, colorCount;
    cin >> h >> w >> colorCount;

    vector<string> a(h);
    for (string &row : a)
        cin >> row;

    DSU dsu(colorCount);

    for (int x = 0; x < w; x++)
        for (int y1 = 0; y1 < h; y1++)
            for (int y2 = y1 + 1; y2 < h; y2++)
                dsu.merge(a[y1][x] - 'A', a[y2][x] - 'A');

    cout << dsu.ccCount;
}