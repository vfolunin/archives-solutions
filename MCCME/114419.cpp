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

    int size, width;
    cin >> size >> width;
    width = min(width * 2 + 1, size);

    vector<long long> p(size);
    for (long long &value : p)
        cin >> value;
    partial_sum(p.begin(), p.end(), p.begin());

    long long res = 0;
    for (int l = 0, r = width - 1; r < p.size(); l++, r++)
        res = max(res, getSum(p, l, r));

    cout << res;
}