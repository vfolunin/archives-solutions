#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int getSum(vector<int> &p, int l, int r) {
    return p[r] - (l ? p[l - 1] : 0);
}

int getRoundedSum(vector<int> &p, int l, int r) {
    int sum = getSum(p, l, r);
    return (sum / 10 + (sum % 10 >= 5)) * 10;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int itemCount, maxPartCount;
    cin >> itemCount >> maxPartCount;
    maxPartCount++;

    vector<int> p(itemCount);
    for (int i = 0; i < p.size(); i++) {
        cin >> p[i];
        if (i)
            p[i] += p[i - 1];
    }

    vector<vector<int>> minCost(itemCount + 1, vector<int>(maxPartCount + 1, 1e9));
    minCost[0].assign(maxPartCount + 1, 0);

    for (int items = 1; items <= itemCount; items++) {
        for (int parts = 1; parts <= maxPartCount; parts++) {
            int &res = minCost[items][parts];
            for (int lastPartItems = 1; lastPartItems <= items; lastPartItems++)
                res = min(res, minCost[items - lastPartItems][parts - 1] + getRoundedSum(p, items - lastPartItems, items - 1));
        }
    }

    cout << *min_element(minCost.back().begin(), minCost.back().end());
}