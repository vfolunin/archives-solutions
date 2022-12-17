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
    for (int y = 0; y < size; y++) {
        a[y][0] = 1;
        for (int x = 1; x <= y; x++)
            a[y][x] = a[y - 1][x - 1] + a[y - 1][x];
    }

    for (int y = 0; y < size; y++) {
        for (int x = 0; x <= y; x++)
            cout << a[y][x] << " ";
        cout << "\n";
    }
}