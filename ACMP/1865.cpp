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

long long getCost(vector<long long> &a, vector<long long> &p, long long minValue, long long maxValue) {
    long long cost = 0;

    int l = lower_bound(a.begin(), a.end(), minValue) - a.begin();
    if (l)
        cost += l * minValue - getSum(p, 0, l - 1);

    int r = upper_bound(a.begin(), a.end(), maxValue) - a.begin();
    if (r < a.size())
        cost += getSum(p, r, a.size() - 1) - (a.size() - r) * maxValue;

    return cost;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int size;
    long long diff;
    cin >> size >> diff;

    vector<long long> a(size);
    for (long long &value : a)
        cin >> value;

    sort(a.begin(), a.end());

    vector<long long> p = a;
    partial_sum(p.begin(), p.end(), p.begin());

    long long res = 1e18;
    for (int i = 0; i < a.size(); i++)
        res = min({ res, getCost(a, p, a[i], a[i] + diff), getCost(a, p, a[i] - diff, a[i]) });

    cout << res;
}