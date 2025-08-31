#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

long long getSum(vector<long long> &p, int l, int r) {
    return p[r] - (l ? p[l - 1] : 0);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    vector<long long> p(size);
    for (long long &value : p)
        cin >> value;

    sort(p.begin(), p.end());
    partial_sum(p.begin(), p.end(), p.begin());

    long long res = 1e18;
    for (int i = 0; i + 1 < p.size(); i++) {
        long long cur = (i + 1) * getSum(p, i, i) - getSum(p, 0, i);
        cur += (p.size() - 1 - i) * getSum(p, p.size() - 1, p.size() - 1) - getSum(p, i + 1, p.size() - 1);
        res = min(res, cur);
    }

    cout << res;
}