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

    if (size == 1) {
        cout << 1;
        return 0;
    }

    vector<vector<long long>> a(size, vector<long long>(size));
    vector<long long> rowSum(a.size()), colSum(a.size());
    int zy = -1, zx = -1;

    for (int y = 0; y < a.size(); y++) {
        for (int x = 0; x < a.size(); x++) {
            cin >> a[y][x];

            rowSum[y] += a[y][x];
            colSum[x] += a[y][x];

            if (!a[y][x]) {
                zy = y;
                zx = x;
            }
        }
    }

    a[zy][zx] = rowSum[zy ^ 1] - rowSum[zy];
    rowSum[zy] += a[zy][zx];
    colSum[zx] += a[zy][zx];

    for (int y = 1; y < a.size(); y++) {
        if (rowSum[0] != rowSum[y]) {
            cout << -1;
            return 0;
        }
    }
    for (int x = 0; x < a.size(); x++) {
        if (rowSum[0] != colSum[x]) {
            cout << -1;
            return 0;
        }
    }

    long long d1Sum = 0, d2Sum = 0;
    for (int i = 0; i < a.size(); i++) {
        d1Sum += a[i][i];
        d2Sum += a[i][a.size() - 1 - i];
    }

    if (rowSum[0] == d1Sum && rowSum[0] == d2Sum)
        cout << a[zy][zx];
    else
        cout << -1;
}