#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct DSU {
    vector<int> id, sz;

    DSU(int n) {
        for (int i = 0; i < n; i++) {
            id.push_back(i);
            sz.push_back(1);
        }
    }

    int find(int i) {
        return id[i] == i ? i : id[i] = find(id[i]);
    }

    void merge(int i, int j) {
        int r1 = find(i), r2 = find(j);
        if (r1 == r2)
            return;
        if (sz[r1] < sz[r2]) {
            id[r1] = r2;
            sz[r2] += sz[r1];
        } else {
            id[r2] = r1;
            sz[r1] += sz[r2];
        }
    }

    int getSize(int i) {
        return sz[find(i)];
    }
};

void solve(int test) {
    vector<string> a;
    while (isalpha(cin.get())) {
        cin.unget();
        a.emplace_back();
        cin >> a.back();
        cin.ignore();
    }

    int h = a.size(), w = a[0].size();
    DSU dsu(h * w);
    static int di[] = { -1, -1, -1, 0, 1, 1, 1, 0 };
    static int dj[] = { -1, 0, 1, 1, 1, 0, -1, -1 };

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (a[i][j] != 'W')
                continue;
            for (int d = 0; d < 8; d++) {
                int ti = i + di[d], tj = j + dj[d];
                if (0 <= ti && ti < h && 0 <= tj && tj < w && a[ti][tj] == 'W')
                    dsu.merge(i * w + j, ti * w + tj);
            }
        }
    }

    if (test)
        cout << "\n";

    cin.unget();
    while (isdigit(cin.get())) {
        cin.unget();
        int row, col;
        cin >> row >> col;
        row--;
        col--;
        cout << dsu.getSize(row * w + col) << "\n";
        cin.ignore();
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    cin.ignore(2);

    for (int i = 0; i < n; i++)
        solve(i);
}