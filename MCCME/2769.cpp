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
    for (int y = 0, x = size / 2, value = 1; value <= size * size; value++) {
        a[y][x] = value;
        y = (y + size - 1) % size;
        x = (x + 1) % size;
        if (a[y][x]) {
            y = (y + 2) % size;
            x = (x + size - 1) % size;
        }
    }

    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++)
            cout << a[y][x] << " ";
        cout << "\n";
    }
}