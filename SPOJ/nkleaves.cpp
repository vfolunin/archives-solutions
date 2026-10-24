#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long getPrice(const vector<long long> &p, const vector<long long> &p2, int l, int r) {
    long long sum = p[r] - (l ? p[l - 1] : 0);
    long long sum2 = p2[r] - (l ? p2[l - 1] : 0);
    return sum2 - l * sum;
}

void rec(vector<vector<long long>> &minCost, int parts, int sizeL, int sizeR, int prevSizeL, int prevSizeR,
         vector<long long> &p, vector<long long> &p2) {
    if (sizeL > sizeR)
        return;

    int size = sizeL + (sizeR - sizeL) / 2;
    int bestPrevSize = prevSizeL;

    for (int prevSize = prevSizeL; prevSize <= prevSizeR && prevSize < size; prevSize++) {
        long long cost = minCost[parts - 1][prevSize] + getPrice(p, p2, prevSize, size - 1);
        if (minCost[parts][size] > cost) {
            minCost[parts][size] = cost;
            bestPrevSize = prevSize;
        }
    }

    rec(minCost, parts, sizeL, size - 1, prevSizeL, bestPrevSize, p, p2);
    rec(minCost, parts, size + 1, sizeR, bestPrevSize, prevSizeR, p, p2);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size, partCount;
    cin >> size >> partCount;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    vector<long long> p(a.size()), p2(a.size());
    for (int i = 0; i < a.size(); i++) {
        p[i] = a[i] + (i ? p[i - 1] : 0);
        p2[i] = 1LL * a[i] * i + (i ? p2[i - 1] : 0);
    }

    vector<vector<long long>> minCost(partCount + 1, vector<long long>(a.size() + 1, 1e18));
    minCost[0][0] = 0;

    for (int parts = 1; parts <= partCount; parts++)
        rec(minCost, parts, 0, a.size(), 0, a.size(), p, p2);

    cout << minCost[partCount][a.size()];
}