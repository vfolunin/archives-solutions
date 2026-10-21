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
    int size;
    cin >> size;

    vector<long long> p(size);
    for (long long &value : p)
        cin >> value;
    partial_sum(p.begin(), p.end(), p.begin());

    vector<vector<long long>> minCost(size, vector<long long>(size, 1e18));
    vector<vector<int>> bestM(size, vector<int>(size));

    for (int i = 0; i < size; i++) {
        minCost[i][i] = 0;
        bestM[i][i] = i;
    }

    for (int len = 2; len <= size; len++) {
        for (int l = 0, r = len - 1; r < size; l++, r++) {
            for (int m = bestM[l][r - 1]; m <= bestM[l + 1][r] && m < r; m++) {
                long long cost = minCost[l][m] + minCost[m + 1][r] + getSum(p, l, r);
                if (minCost[l][r] > cost) {
                    minCost[l][r] = cost;
                    bestM[l][r] = m;
                }
            }
        }
    }

    cout << minCost[0][size - 1];
}