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

    vector<vector<int>> a(h, vector<int>(w));
    vector<int> rowSum(h);

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            cin >> a[y][x];
            rowSum[y] += a[y][x];
        }
    }

    int y = min_element(rowSum.begin(), rowSum.end()) - rowSum.begin();
    for (int value : a[y])
        cout << value << " ";
}