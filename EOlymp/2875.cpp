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

    void add(int l, int r, int v) {
        add(l, v);
        add(r + 1, -v);
    }

    int get(int i) {
        return sum(i);
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int size, opCount;
    cin >> size >> opCount;

    BIT bit(size);

    for (int i = 0; i < opCount; i++) {
        char op;
        cin >> op;

        if (op == 'A') {
            int l, r, value;
            cin >> l >> r >> value;
            bit.add(l, r, value);
        } else {
            int index;
            cin >> index;
            cout << bit.get(index) << "\n";
        }
    }
}