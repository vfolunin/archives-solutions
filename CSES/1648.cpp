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

    BIT(vector<long long> &a) {
        f.resize(a.size());
        for (int i = 0; i < a.size(); i++)
            add(i, a[i]);
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size, queryCount;
    cin >> size >> queryCount;

    vector<long long> a(size);
    for (long long &x : a)
        cin >> x;

    BIT bit(a);

    for (int i = 0; i < queryCount; i++) {
        int type;
        cin >> type;

        if (type == 1) {
            int index, val;
            cin >> index >> val;
            index--;
            bit.add(index, val - a[index]);
            a[index] = val;
        } else {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            cout << bit.sum(l, r) << "\n";
        }
    }
}