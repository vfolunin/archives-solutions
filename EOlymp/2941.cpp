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

    void set(int i, int v) {
        add(i, v - sum(i, i));
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size, opCount;
    cin >> size >> opCount;

    BIT bit(size);
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;
        bit.set(i, value);
    }

    for (int i = 0; i < opCount; i++) {
        char op;
        cin >> op;

        if (op == '?') {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            cout << bit.sum(l, r) << "\n";
        } else {
            int index, value;
            cin >> index >> value;
            index--;
            bit.set(index, value);
        }
    }
}