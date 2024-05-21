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
    vector<vector<int>> a(h, vector<int>(w));
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            cin >> a[y][x];
            rowSum[y] += a[y][x];
            colSum[x] += a[y][x];
        }
    }

    for (int targetSum : { rowSum[0], rowSum[1] }) {
        if (count_if(rowSum.begin(), rowSum.end(), [&](int sum) { return sum != targetSum; }) != 1 ||
            count_if(colSum.begin(), colSum.end(), [&](int sum) { return sum != targetSum; }) != 1)
            continue;

        auto rowIt = find_if(rowSum.begin(), rowSum.end(), [&](int sum) { return sum != targetSum; });
        auto colIt = find_if(colSum.begin(), colSum.end(), [&](int sum) { return sum != targetSum; });
        if (*rowIt == *colIt) {
            cout << "Yes";
            return 0;
        }                
    }

    cout << "No";
}