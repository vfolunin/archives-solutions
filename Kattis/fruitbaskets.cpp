#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> getSums(vector<int> &a) {
    vector<int> sums;

    for (int mask = 0; mask < (1 << a.size()); mask++) {
        int sum = 0;

        for (int bit = 0; bit < a.size(); bit++)
            if (mask & (1 << bit))
                sum += a[bit];

        sums.push_back(sum);
    }

    return sums;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    vector<int> values(size);
    for (int &value : values)
        cin >> value;

    int aSize = size / 2;
    vector<int> a(values.begin(), values.begin() + aSize);
    vector<int> b(values.begin() + aSize, values.end());

    vector<int> aSums = getSums(a);
    vector<int> bSums = getSums(b);

    sort(bSums.begin(), bSums.end());

    vector<long long> bPref(bSums.size());
    for (int i = 0; i < bSums.size(); i++)
        bPref[i] = bSums[i] + (i ? bPref[i - 1] : 0);

    long long res = 0;

    for (int aSum : aSums) {
        int from = lower_bound(bSums.begin(), bSums.end(), 200 - aSum) - bSums.begin();
        res += aSum * (bSums.size() - from);
        res += bPref.back() - (from ? bPref[from - 1] : 0);
    }

    cout << res;
}