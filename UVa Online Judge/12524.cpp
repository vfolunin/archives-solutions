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

void rec(vector<vector<long long>> &res, int parts, int sizeL, int sizeR, int bestPrevSizeL, int bestPrevSizeR,
         vector<int> &pos, vector<long long> &pHeight, vector<long long> &pProduct) {
    if (sizeL > sizeR)
        return;

    int size = sizeL + (sizeR - sizeL) / 2;
    int bestPrevSize = bestPrevSizeL;

    for (int prevSize = bestPrevSizeL; prevSize <= bestPrevSizeR && prevSize < size; prevSize++) {
        long long partPrice = getSum(pHeight, prevSize, size - 1) * pos[size - 1] - getSum(pProduct, prevSize, size - 1);

        if (res[parts][size] > res[parts - 1][prevSize] + partPrice) {
            res[parts][size] = res[parts - 1][prevSize] + partPrice;
            bestPrevSize = prevSize;
        }
    }

    rec(res, parts, sizeL, size - 1, bestPrevSizeL, bestPrevSize, pos, pHeight, pProduct);
    rec(res, parts, size + 1, sizeR, bestPrevSize, bestPrevSizeR, pos, pHeight, pProduct);
}

bool solve() {
    int size, partCount;
    if (!(cin >> size >> partCount))
        return 0;

    vector<int> pos(size), height(size);
    for (int i = 0; i < size; i++)
        cin >> pos[i] >> height[i];

    vector<long long> pHeight(size), pProduct(size);
    for (int i = 0; i < size; i++) {
        pHeight[i] = height[i] + (i ? pHeight[i - 1] : 0);
        pProduct[i] = 1LL * pos[i] * height[i] + (i ? pProduct[i - 1] : 0);
    }

    vector<vector<long long>> res(partCount + 1, vector<long long>(size + 1, 1e18));
    res[0][0] = 0;

    for (int parts = 1; parts <= partCount; parts++)
        rec(res, parts, 0, size, 0, size, pos, pHeight, pProduct);

    cout << res[partCount][size] << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}