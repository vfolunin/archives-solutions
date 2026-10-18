#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long getSum(vector<long long> &p, int l, int r) {
    return p[r] - (l ? p[l - 1] : 0);
}

vector<vector<long long>> preparePartPrice(vector<int> &a) {
    vector<long long> pCount(a.size());
    vector<long long> pSum(a.size());
    for (int i = 0; i < a.size(); i++) {
        pCount[i] = a[i] + (i ? pCount[i - 1] : 0);
        pSum[i] = a[i] * (i + 1LL) + (i ? pSum[i - 1] : 0);
    }

    vector<vector<long long>> partPrice(a.size(), vector<long long>(a.size()));
    for (int l = 0; l < a.size(); l++) {
        for (int m = l, r = l; r < a.size(); r++) {
            while (getSum(pCount, l, m) * 2 < getSum(pCount, l, r))
                m++;

            long long leftPrice = (m + 1LL) * getSum(pCount, l, m) - getSum(pSum, l, m);
            long long rightPrice = getSum(pSum, m, r) - (m + 1LL) * getSum(pCount, m, r);
            partPrice[l][r] = leftPrice + rightPrice;
        }
    }
    return partPrice;
}

long long getPartPrice(vector<int> &a, int l, int r) {
    static vector<vector<long long>> partPrice;
    if (partPrice.empty())
        partPrice = preparePartPrice(a);
    return partPrice[l][r];
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size, partCount;
    cin >> size >> partCount;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    vector<vector<long long>> res(partCount + 1, vector<long long>(a.size() + 1, 1e18));
    vector<vector<int>> bestPrevSize(partCount + 1, vector<int>(a.size() + 1));
    res[0][0] = 0;

    for (int parts = 1; parts <= partCount; parts++) {
        for (int size = a.size(); size >= 1; size--) {
            int prevSizeL = bestPrevSize[parts - 1][size];
            int prevSizeR = size == a.size() ? size - 1 : min(size - 1, bestPrevSize[parts][size + 1]);

            for (int prevSize = prevSizeL; prevSize <= prevSizeR; prevSize++) {
                long long partPrice = getPartPrice(a, prevSize, size - 1);
                if (res[parts][size] > res[parts - 1][prevSize] + partPrice) {
                    res[parts][size] = res[parts - 1][prevSize] + partPrice;
                    bestPrevSize[parts][size] = prevSize;
                }
            }
        }
    }

    cout << res[partCount][a.size()];
}