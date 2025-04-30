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

    if (size == 2) {
        cout << "1 1";
        return 0;
    }

    vector<vector<int>> a(size, vector<int>(size));
    for (int y = 0; y < size; y++)
        for (int x = 0; x < size; x++)
            cin >> a[y][x];

    for (int i = 0; i < size; i++) {
        int j = (i + 1) % size, k = (i + 2) % size;
        cout << (a[i][j] + a[i][k] - a[j][k]) / 2 << " ";
    }
}