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

    int size, queryCount;
    cin >> size >> queryCount;

    BIT bit(size);

    for (int i = 0; i < queryCount; i++) {
        char op;
        cin >> op;

        if (op == 'F') {
            int index;
            cin >> index;
            index--;
            bit.add(index, bit.sum(index, index) ? -1 : 1);
        } else {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            cout << bit.sum(l, r) << "\n";
        }
    }
}