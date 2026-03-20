#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int rec(int mask, vector<int> &a, int price, vector<int> &memo) {
    int &res = memo[mask];
    if (res != -1)
        return res;

    if (!mask)
        return 0;

    res = 1e9;
    for (int bit = 0; bit < a.size(); bit++)
        if (mask & (1 << bit))
            res = min(res, rec(mask ^ (1 << bit), a, price, memo) + a[bit]);

    for (int submask = mask; submask; submask = (submask - 1) & mask) {
        int sum = 0;
        for (int bit = 0; bit < a.size(); bit++)
            if (submask & (1 << bit))
                sum += a[bit];

        if (sum == 1000)
            res = min(res, rec(mask ^ submask, a, price, memo) + price);
    }

    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size, price;
    cin >> size >> price;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    vector<int> memo(1 << a.size(), -1);
    cout << rec((1 << a.size()) - 1, a, price, memo);
}