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
    vector<int> rowSum(size);
    vector<int> colSum(size);

    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {
            cin >> a[y][x];
            rowSum[y] += a[y][x];
            colSum[x] += a[y][x];
        }
    }

    int y = max_element(rowSum.begin(), rowSum.end()) - rowSum.begin();
    int x = min_element(colSum.begin(), colSum.end()) - colSum.begin();

    cout << a[y][x];
}