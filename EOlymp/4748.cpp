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
    for (int index = 1, diag = 0; index <= size * size; diag++) {
        if (diag % 2) {
            for (int y = diag, x = 0; 0 <= y && x < size && index <= size * size; y--, x++)
                if (y < size)
                    a[y][x] = index++;
        } else {
            for (int y = 0, x = diag; y < size && 0 <= x && index <= size * size; y++, x--)
                if (x < size)
                    a[y][x] = index++;
        }
    }

    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++)
            cout << a[y][x] << " ";
        cout << "\n";
    }
}