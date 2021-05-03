#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct BIT {
    vector<int> f;

    int sum(int r) {
        int res = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            res += f[r];
        return res;
    }

    int sum(int l, int r) {
        return sum(r) - (l ? sum(l - 1) : 0);
    }

    void add(int i, int v) {
        for (; i < f.size(); i |= i + 1)
            f[i] += v;
    }

    BIT(int size) {
        f.resize(size);
    }
};

void solve() {
    int movieCount, queryCount;
    cin >> movieCount >> queryCount;

    BIT bit(movieCount + queryCount);
    map<int, int> position;

    for (int id = 0; id < movieCount; id++) {
        position[id] = queryCount + id;
        bit.add(position[id], 1);
    }

    for (int i = 0; i < queryCount; i++) {
        int id;
        cin >> id;
        id--;

        cout << bit.sum(position[id]) - 1 << (i + 1 < queryCount ? " " : "\n");
        bit.add(position[id], -1);
        position[id] = queryCount - 1 - i;
        bit.add(position[id], 1);
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}