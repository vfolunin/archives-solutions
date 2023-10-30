#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct BIT {
    vector<long long> f;

    BIT(int size) : f(size) {}

    long long sum(int r) {
        long long res = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            res += f[r];
        return res;
    }

    long long sum(int l, int r) {
        return sum(r) - (l ? sum(l - 1) : 0);
    }

    void add(int i, int v) {
        for (; i < f.size(); i |= i + 1)
            f[i] += v;
    }
};

int getValue(BIT &bit, int index) {
    int l = 0, r = 1e5;
    while (l + 1 < r) {
        int m = l + (r - l) / 2;
        if (index < bit.sum(m, 1e5))
            l = m;
        else
            r = m;
    }
    return l;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int opCount;
    cin >> opCount;

    BIT bit(1e5 + 1);

    for (int i = 0; i < opCount; i++) {
        int op;
        cin >> op;

        if (op == 1) {
            int value;
            cin >> value;

            cout << bit.sum(value, 1e5) << "\n";
            bit.add(value, 1);
        } else {
            int index;
            cin >> index;

            bit.add(getValue(bit, index), -1);
        }
    }
}