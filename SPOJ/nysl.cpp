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

bool solve(int test) {
    int size;
    cin >> size;

    if (!size)
        return 0;

    BIT bit(size);
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        bit.set(i, value);
    }

    cout << "Case " << test << ":\n";
    while (1) {
        string query;
        cin >> query;

        if (query == "S") {
            int index, value;
            cin >> index >> value;

            bit.set(index - 1, value);
        } else if (query == "M") {
            int l, r;
            cin >> l >> r;

            cout << bit.sum(l - 1, r - 1) << "\n";
        } else {
            break;
        }
    }
    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}