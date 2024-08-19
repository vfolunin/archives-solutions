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

    int targetSum = 0;
    for (int y = 0; y < size; y++)
        targetSum += a[y][y];

    int sum = 0;
    for (int y = 0; y < size; y++)
        sum += a[y][size - 1 - y];

    if (sum != targetSum) {
        cout << -1;
        return 0;
    }

    for (int y = 0; y < size; y++) {
        sum = 0;
        for (int x = 0; x < size; x++)
            sum += a[y][x];

        if (sum != targetSum) {
            cout << -1;
            return 0;
        }
    }

    for (int x = 0; x < size; x++) {
        sum = 0;
        for (int y = 0; y < size; y++)
            sum += a[y][x];

        if (sum != targetSum) {
            cout << -1;
            return 0;
        }
    }

    cout << targetSum;
}