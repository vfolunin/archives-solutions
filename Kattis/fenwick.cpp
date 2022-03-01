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

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int size, opCount;
    cin >> size >> opCount;

    BIT t(size);

    for (int i = 0; i < opCount; i++) {
        char op;
        int index;
        cin >> op >> index;

        if (op == '+') {
            int value;
            cin >> value;
            t.add(index, value);
        } else {
            cout << (index ? t.sum(index - 1) : 0) << "\n";
        }
    }
}