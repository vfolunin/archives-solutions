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

    vector<vector<int>> a(size, vector<int>(size, 1));
    for (int y = 1; y < size; y++)
        for (int x = 1; x < size; x++)
            a[y][x] = a[y - 1][x] + a[y][x - 1];

    cout << a[size - 1][size - 1];
}