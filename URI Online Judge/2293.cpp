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

    vector<int> rowSum(h), colSum(w);

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            int amount;
            cin >> amount;
            rowSum[y] += amount;
            colSum[x] += amount;
        }
    }

    int res = *max_element(rowSum.begin(), rowSum.end());
    res = max(res, *max_element(colSum.begin(), colSum.end()));

    cout << res << "\n";
}