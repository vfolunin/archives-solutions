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

    int size, windowSize;
    cin >> size >> windowSize;

    vector<long long> p(size);
    for (long long &value : p)
        cin >> value;
    partial_sum(p.begin(), p.end(), p.begin());

    vector<long long> lMax(p.size());
    for (int i = windowSize; i < p.size(); i++)
        lMax[i] = max(lMax[i - 1], getSum(p, i - windowSize, i - 1));

    vector<long long> rMax(p.size());
    for (int i = p.size() - 1 - windowSize; i >= 0; i--)
        rMax[i] = max(rMax[i + 1], getSum(p, i + 1, i + windowSize));

    long long res = 1e18;
    for (int l = 0, r = windowSize - 1; r < size; l++, r++)
        res = min(res, max(lMax[l], rMax[r]));

    cout << res;
}