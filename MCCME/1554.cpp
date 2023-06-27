#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int aSize;
    cin >> aSize;

    vector<int> a(aSize);
    for (int &value : a)
        cin >> value;

    int bSize;
    cin >> bSize;

    long long den = 1;
    for (int i = 0; i < bSize; i++) {
        int value;
        cin >> value;
        den = lcm(den, value);
    }

    int res = 1e9;

    for (int mask = 0; mask < (1 << a.size()); mask++) {
        int ones = 0;
        long long num = 1;

        for (int bit = 0; bit < a.size(); bit++) {
            if (mask & (1 << bit)) {
                ones++;
                num *= a[bit];
            }
        }

        if (num % den == 0)
            res = min(res, ones);
    }

    cout << (res != 1e9 ? res : 0);
}