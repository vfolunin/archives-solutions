#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<long long> getSums(const vector<int> &a) {
    vector<long long> sums;

    for (int mask = 0; mask < (1 << a.size()); mask++) {
        long long sum = 0;

        for (int bit = 0; bit < a.size(); bit++)
            if (mask & (1 << bit))
                sum += a[bit];

        sums.push_back(sum);
    }

    sort(sums.begin(), sums.end());
    return sums;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size, targetSum;
    cin >> size >> targetSum;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    vector<long long> lSums = getSums({ a.begin(), a.begin() + a.size() / 2 });
    long long res = 0;

    for (long long sum : getSums({ a.begin() + a.size() / 2, a.end() })) {
        if (sum <= targetSum) {
            auto [lIt, rIt] = equal_range(lSums.begin(), lSums.end(), targetSum - sum);
            res += rIt - lIt;
        }
    }
    
    cout << res;
}