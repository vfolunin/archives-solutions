#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

long long getSum(vector<int> &p, int l, int r) {
    return p[r] - (l ? p[l - 1] : 0);
}

void rec(vector<vector<long long>> &res, int parts, int sizeL, int sizeR, int bestPrevSizeL, int bestPrevSizeR, vector<int> &p) {
    if (sizeL > sizeR)
        return;

    int size = sizeL + (sizeR - sizeL) / 2;
    int bestPrevSize = bestPrevSizeL;

    for (int prevSize = bestPrevSizeL; prevSize <= bestPrevSizeR && prevSize < size; prevSize++) {
        long long part1Count = getSum(p, prevSize, size - 1), part0Count = size - prevSize - part1Count;
        long long partPrice = part0Count * part1Count;

        if (res[parts][size] > res[parts - 1][prevSize] + partPrice) {
            res[parts][size] = res[parts - 1][prevSize] + partPrice;
            bestPrevSize = prevSize;
        }
    }

    rec(res, parts, sizeL, size - 1, bestPrevSizeL, bestPrevSize, p);
    rec(res, parts, size + 1, sizeR, bestPrevSize, bestPrevSizeR, p);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size, partCount;
    cin >> size >> partCount;

    vector<int> p(size);
    for (int &value : p)
        cin >> value;
    partial_sum(p.begin(), p.end(), p.begin());

    vector<vector<long long>> res(partCount + 1, vector<long long>(size + 1, 1e18));
    res[0][0] = 0;

    for (int parts = 1; parts <= partCount; parts++)
        rec(res, parts, 0, size, 0, size, p);

    cout << res[partCount][size];
}