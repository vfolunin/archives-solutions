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
        if (l > r)
            return 0;
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

    vector<int> a(size);
    for (int &value : a) {
        cin >> value;
        value--;
    }

    BIT l(size), r(size);
    for (int value : a)
        r.add(value, 1);

    long long invertedTriples = 0;
    for (int value : a) {
        r.add(value, -1);
        invertedTriples += 1LL * l.sum(value + 1, size - 1) * r.sum(0, value - 1);
        l.add(value, 1);
    }

    cout << invertedTriples << "\n";
}