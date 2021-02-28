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

    BIT(vector<int> &v) {
        f.resize(v.size());
        for (int i = 0; i < v.size(); i++)
            add(i, v[i]);
    }
};

bool solve(int test) {
    int n;
    cin >> n;

    if (!n)
        return 0;

    vector<int> v(n);
    for (int &x : v)
        cin >> x;

    BIT bit(v);

    if (test > 1)
        cout << "\n";
    cout << "Case " << test << ":\n";

    while (1) {
        string op;
        cin >> op;

        if (op == "S") {
            int i, v;
            cin >> i >> v;
            bit.add(i - 1, v - bit.sum(i - 1, i - 1));
        } else if (op == "M") {
            int l, r;
            cin >> l >> r;
            cout << bit.sum(l - 1, r - 1) << "\n";
        } else {
            break;
        }
    }

    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (int test = 1; solve(test); test++);
}