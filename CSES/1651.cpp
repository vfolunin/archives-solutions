#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct BIT {
    vector<long long> f;

    long long sum(int r) {
        long long res = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            res += f[r];
        return res;
    }

    long long sum(int l, int r) {
        return sum(r) - (l ? sum(l - 1) : 0);
    }

    void add(int i, long long v) {
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

    BIT bit(size + 1);

    for (int i = 0; i < size; i++) {
        int x;
        cin >> x;
        bit.add(i, x);
        bit.add(i + 1, -x);
    }

    for (int i = 0; i < queryCount; i++) {
        int type;
        cin >> type;

        if (type == 1) {
            int l, r, val;
            cin >> l >> r >> val;
            bit.add(l - 1, val);
            bit.add(r, -val);
        } else {
            int index;
            cin >> index;
            cout << bit.sum(index - 1) << "\n";
        }
    }
}