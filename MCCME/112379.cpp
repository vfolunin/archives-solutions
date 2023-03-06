#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void check(bool condition) {
    if (!condition) {
        cout << "NO";
        exit(0);
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    vector<vector<int>> a(size, vector<int>(size));
    vector<int> used(size * size);
    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {
            cin >> a[y][x];
            check(1 <= a[y][x] && a[y][x] <= size * size);
            used[a[y][x] - 1] = 1;
        }
    }
    check(!count(used.begin(), used.end(), 0));

    int targetSum = 0;
    for (int y = 0; y < size; y++)
        targetSum += a[y][y];

    int sum = 0;
    for (int y = 0; y < size; y++)
        sum += a[y][size - 1 - y];
    check(sum == targetSum);

    for (int y = 0; y < size; y++) {
        sum = 0;
        for (int x = 0; x < size; x++)
            sum += a[y][x];
        check(sum == targetSum);
    }

    for (int x = 0; x < size; x++) {
        sum = 0;
        for (int y = 0; y < size; y++)
            sum += a[y][x];
        check(sum == targetSum);
    }

    cout << "YES";
}