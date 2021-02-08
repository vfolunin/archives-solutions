#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct BigInteger {
    vector<int> d;
    int size;
public:
    BigInteger(int size) : size(size) {
        d.resize(1.1e6);
    }

    BigInteger operator + (const BigInteger &that) const {
        BigInteger res(0);

        int carry = 0;
        for (int i = 0; i < max(size, that.size) || carry; i++) {
            int x = d[i] + that.d[i] + carry;
            res.d[i] = x % 10;
            carry = x / 10;
        }

        res.size = max(size, that.size) + 1;
        while (res.size > 1 && res.d[res.size - 1] == 0)
            res.size--;
        return res;
    }

    void print() const {
        for (int i = size - 1; i >= 0; i--)
            cout << d[i];
    }
};

void solve(int test) {
    int size;
    cin >> size;

    BigInteger a(size), b(size);
    for (int i = size - 1; i >= 0; i--)
        cin >> a.d[i] >> b.d[i];

    if (test)
        cout << "\n";
    (a + b).print();
    cout << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve(i);
}