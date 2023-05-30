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
    vector<int> zeroRow(size), zeroCol(size);

    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {
            cin >> a[y][x];
            if (!a[y][x])
                zeroRow[y] = zeroCol[x] = 1;
        }
    }

    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++)
            cout << (zeroRow[y] || zeroCol[x] ? 0 : a[y][x]) << " ";
        cout << "\n";
    }
}