#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long rec(vector<int> &a, int i, int mask, map<pair<int, int>, long long> &memo) {
    if (memo.count({ i, mask }))
        return memo[{ i, mask }];
    long long &res = memo[{ i, mask }];

    if (i == a.size() - 1)
        return res = 1;

    for (int submask = mask; 1; submask = (submask - 1) & mask) {
        if (submask % 41 == a[i + 1])
            res += rec(a, i + 1, submask, memo);
        if (!submask)
            break;
    }
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size, bitSize;
    cin >> size >> bitSize;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    map<pair<int, int>, long long> memo;
    long long res = 0;
    for (int mask = a[0]; mask < (1 << bitSize); mask += 41)
        res += rec(a, 0, mask, memo);

    cout << res;
}