#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int h, w;
    cin >> h >> w;

    vector<vector<int>> cost(h, vector<int>(w));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> cost[i][j];
            if (i) {
                int pCost = 1e9;
                for (int pj = j - 1; pj <= j + 1; pj++)
                    if (0 <= pj && pj < w)
                        pCost = min(pCost, cost[i - 1][pj]);
                cost[i][j] += pCost;
            }
        }
    }

    cout << *min_element(cost.back().begin(), cost.back().end());
}