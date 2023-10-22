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

    int size;
    cin >> size;

    vector<vector<int>> a(size, vector<int>(size));
    for (int y = 0; y < size; y++)
        for (int x = 0; x < size; x++)
            cin >> a[y][x];

    vector<vector<int>> res(size + 1, vector<int>(size));
    for (int sum = 1; sum <= size; sum++) {
        for (int x = 0; x < size; x++) {
            res[sum][x] = a[sum - 1][x];
            if (x) {
                res[sum][x] = max(res[sum][x], res[sum][x - 1]);
                for (int y = 0; y < size && y + 1 < sum; y++)
                    res[sum][x] = max(res[sum][x], res[sum - y - 1][x - 1] + a[y][x]);
            }
        }
    }

    cout << res[size][size - 1];
}