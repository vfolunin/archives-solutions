#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int h, w;
    cin >> h >> w;

    vector<vector<int>> a(h, vector<int>(w));
    vector<int> colSum(w);
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            cin >> a[y][x];
            colSum[x] += a[y][x];
        }
    }

    vector<int> order(w);
    iota(order.begin(), order.end(), 0);
    stable_sort(order.begin(), order.end(), [&](int lhs, int rhs) {
        return colSum[lhs] > colSum[rhs];
    });

    for (int y = 0; y < h; y++) {
        for (int x : order)
            cout << a[y][x] << " ";
        cout << "\n";
    }
}