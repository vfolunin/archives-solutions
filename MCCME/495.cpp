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

    vector<pair<int, pair<int, int>>> cells;
    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {
            int value;
            cin >> value;
            if ((y == x) ^ !value) {
                cout << -1;
                return 0;
            }
            if (y != x)
                cells.push_back({ value, { y, x } });
        }
    }

    sort(cells.rbegin(), cells.rend());

    vector<int> res(size, 1e9);
    for (auto &[value, cell] : cells) {
        auto &[y, x] = cell;
        res[y] = res[x] = value;
    }

    for (auto &[value, cell] : cells) {
        auto &[y, x] = cell;
        if (max(res[y], res[x]) != value) {
            cout << -1;
            return 0;
        }
    }

    for (int value : res)
        cout << value << " ";
}