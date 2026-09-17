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

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    vector<int> pos(size);
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;
        pos[value - 1] = i;
    }

    BIT bit(size);
    for (int i = 0; i < size; i++)
        bit.add(i, 1);

    for (int l = 0, r = size - 1; l <= r; l++, r--) {
        cout << bit.sum(0, pos[l]) - 1 << "\n";
        bit.add(pos[l], -1);

        if (l == r)
            break;

        cout << bit.sum(pos[r], size - 1) - 1 << "\n";
        bit.add(pos[r], -1);
    }
}