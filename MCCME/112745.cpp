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

    vector<long long> p(size);
    for (long long &value : p)
        cin >> value;
    partial_sum(p.begin(), p.end(), p.begin());

    vector<long long> l(size);
    for (int i = width; i < size; i++) {
        l[i] = getSum(p, i - width, i - 1);
        if (i > width)
            l[i] = max(l[i], l[i - 1]);
    }

    vector<long long> r(size);
    for (int i = size - 1 - width; i >= 0; i--) {
        r[i] = getSum(p, i + 1, i + width);
        if (i < size - 1 - width)
            r[i] = max(r[i], r[i + 1]);
    }

    long long res = 1e18;
    for (int i = 0; i + width <= size; i++)
        res = min(res, max(l[i], r[i + width - 1]));
    
    cout << res;
}