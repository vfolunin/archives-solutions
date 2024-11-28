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

    long long sum(int r, int mod) {
        long long res = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            res = (res + f[r]) % mod;
        return res;
    }

    long long sum(int l, int r, int mod) {
        return (sum(r, mod) - (l ? sum(l - 1, mod) : 0) + mod) % mod;
    }

    void add(int i, int v, int mod) {
        for (; i < f.size(); i |= i + 1)
            f[i] = (f[i] + v) % mod;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int index, size, mod;
    cin >> index >> size >> mod;

    BIT bit(index);
    for (int i = 0; i < size; i++)
        bit.add(i, 1, mod);
    for (int i = size; i < index; i++)
        bit.add(i, bit.sum(i - size, i - 1, mod), mod);

    cout << bit.sum(index - 1, index - 1, mod);
}