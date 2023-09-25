#include <iostream>
#include <cmath>
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

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    BIT bit(size);
    for (int i = 0; i < size; i++)
        bit.add(i, a[i]);

    int opCount;
    cin >> opCount;

    for (int i = 0; i < opCount; i++) {
        char op;
        cin >> op;

        if (op == 's') {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            cout << bit.sum(l, r) << " ";
        } else {
            int index, value;
            cin >> index >> value;
            index--;
            bit.add(index, value - a[index]);
            a[index] = value;
        }
    }
}