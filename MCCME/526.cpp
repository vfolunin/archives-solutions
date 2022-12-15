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

    int y = size - 1, x = 0, res = a[y][x];
    while (y != 0 || x != size - 1) {
        if (x == size - 1 || y > 0 && a[y - 1][x] > a[y][x + 1])
            y--;
        else
            x++;
        res += a[y][x];
    }

    cout << res;
}