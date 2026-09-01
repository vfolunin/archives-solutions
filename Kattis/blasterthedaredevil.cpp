#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Fraction {
    long long num, den;

    bool operator < (const Fraction &that) const {
        return num * that.den < that.num * den;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    map<Fraction, int> deltas;
    for (int i = 0; i < size; i++) {
        int x, y1, y2;
        cin >> x >> y1 >> y2;

        deltas[{ y1, x }]++;
        deltas[{ y2, x }]--;
    }

    int cur = 0, res = 0;
    for (auto &[_, delta] : deltas) {
        cur += delta;
        res = max(res, cur);
    }

    cout << res;
}