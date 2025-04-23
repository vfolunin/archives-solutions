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

    for (int h = 20; h; h--) {
        for (int x = 0; x < size; x++) {
            int res = 0;
            for (int y = 0; y < size; y++)
                if (a[y][x] >= h)
                    res = y * size + x + 1;

            cout << res << " ";
        }
        cout << "\n";
    }
}