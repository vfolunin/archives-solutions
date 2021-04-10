#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    int size;
    if (!(cin >> size))
        return 0;

    vector<vector<int>> a(size, vector<int>(size));
    int y = 0, x = size / 2;
    for (int i = 1; i <= size * size; i++) {
        a[y][x] = i;
        y = (y + size - 1) % size;
        x = (x + 1) % size;
        if (a[y][x]) {
            y = (y + 2) % size;
            x = (x + size - 1) % size;
        }
    }

    if (test)
        cout << "\n";
    cout << "n=" << size << ", sum=" << size * (size * size + 1) / 2 << "\n";
    int w = to_string(size * size).size() + 1;
    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++)
            cout << setw(w) << a[y][x];
        cout << "\n";
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int i = 0; solve(i); i++);
}