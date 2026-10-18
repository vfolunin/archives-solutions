#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

long long getPartPrice(vector<long long> &p, int l, int r) {
    long long price = p[r] - (l ? p[l - 1] : 0);
    return price * price;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size, partCount;
    cin >> size >> partCount;

    vector<long long> p(size);
    for (long long &value : p)
        cin >> value;
    partial_sum(p.begin(), p.end(), p.begin());

    vector<vector<long long>> res(partCount + 1, vector<long long>(p.size() + 1, 1e18));
    vector<vector<int>> bestPrevSize(partCount + 1, vector<int>(p.size() + 1));
    res[0][0] = 0;

    for (int parts = 1; parts <= partCount; parts++) {
        for (int size = p.size(); size >= 1; size--) {
            int prevSizeL = bestPrevSize[parts - 1][size];
            int prevSizeR = size == p.size() ? size - 1 : min(size - 1, bestPrevSize[parts][size + 1]);

            for (int prevSize = prevSizeL; prevSize <= prevSizeR; prevSize++) {
                long long partPrice = getPartPrice(p, prevSize, size - 1);
                if (res[parts][size] > res[parts - 1][prevSize] + partPrice) {
                    res[parts][size] = res[parts - 1][prevSize] + partPrice;
                    bestPrevSize[parts][size] = prevSize;
                }
            }
        }
    }

    cout << res[partCount][p.size()];
}