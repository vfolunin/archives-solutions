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
    int offset = 0;
    for (int fromY = 0; fromY < size; fromY += 4) {
        for (int fromX = 0; fromX < size; fromX += 4) {
            for (int y = 0; y < 4; y++)
                for (int x = 0; x < 4; x++)
                    a[fromY + y][fromX + x] = offset + y * 4 + x;
            offset += 16;
        }
    }

    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++)
            cout << a[y][x] << " ";
        cout << "\n";
    }
}