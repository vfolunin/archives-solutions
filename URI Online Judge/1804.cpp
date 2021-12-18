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

    BIT(int size) {
        f.resize(size);
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int size;
    cin >> size;

    BIT bit(size);
    for (int i = 0; i < size; i++) {
        int x;
        cin >> x;
        bit.add(i, x);
    }

    char type;
    int arg;
    while (cin >> type >> arg) {
        arg--;
        if (type == 'a')
            bit.add(arg, -bit.sum(arg, arg));
        else
            cout << bit.sum(arg - 1) << "\n";
    }
}