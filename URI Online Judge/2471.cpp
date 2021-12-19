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
    vector<int> rowSum(size), colSum(size);

    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {
            cin >> a[y][x];
            rowSum[y] += a[y][x];
            colSum[x] += a[y][x];
        }
    }

    int sum;
    if (rowSum[0] == rowSum[1] || rowSum[0] == rowSum[2])
        sum = rowSum[0];
    else
        sum = rowSum[1];

    int y = 0;
    while (rowSum[y] == sum)
        y++;

    int x = 0;
    while (colSum[x] == sum)
        x++;

    cout << sum - (rowSum[y] - a[y][x]) << " " << a[y][x] << "\n";
}