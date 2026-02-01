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
         vector<long long> &pPos, vector<long long> &pPosI, vector<long long> &pPos2) {
    if (sizeL > sizeR)
        return;

    int size = sizeL + (sizeR - sizeL) / 2;
    int bestPrevSize = bestPrevSizeL;

    for (int prevSize = bestPrevSizeL; prevSize <= bestPrevSizeR && prevSize < size; prevSize++) {
        long long partPrice = getSum(pPosI, prevSize, size - 1);
        partPrice -= prevSize * getSum(pPos, prevSize, size - 1);
        partPrice -= getSum(pPos2, prevSize, size - 1);

        if (res[parts][size] > res[parts - 1][prevSize] + partPrice) {
            res[parts][size] = res[parts - 1][prevSize] + partPrice;
            bestPrevSize = prevSize;
        }
    }

    rec(res, parts, sizeL, size - 1, bestPrevSizeL, bestPrevSize, pPos, pPosI, pPos2);
    rec(res, parts, size + 1, sizeR, bestPrevSize, bestPrevSizeR, pPos, pPosI, pPos2);
}

void solve(int test) {
    string letters, s;
    int partCount;
    cin >> letters >> partCount >> s;

    vector<long long> pPos(s.size()), pPosI(s.size()), pPos2(s.size());
    for (int i = 0; i < s.size(); i++) {
        int pos = letters.find(s[i]);

        pPos[i] = pos + (i ? pPos[i - 1] : 0);
        pPosI[i] = 1LL * pos * i + (i ? pPosI[i - 1] : 0);
        pPos2[i] = 1LL * pos * pos + (i ? pPos2[i - 1] : 0);
    }

    vector<vector<long long>> res(partCount + 1, vector<long long>(s.size() + 1, 1e18));
    res[0][0] = 0;

    for (int parts = 1; parts <= partCount; parts++)
        rec(res, parts, 0, s.size(), 0, s.size(), pPos, pPosI, pPos2);

    cout << "Case " << test << ": " << res[partCount][s.size()] << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 1; test <= testCount; test++)
        solve(test);
}