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

    int coordCount, capacity;
    cin >> coordCount >> capacity;

    vector<map<int, int>> coords(2);
    for (int i = 0; i < coordCount; i++) {
        int coord, amount;
        cin >> coord >> amount;

        if (coord > 0)
            coords[0][coord] += amount;
        else
            coords[1][-coord] += amount;
    }

    long long res = 0;
    for (map<int, int> &coords : coords) {
        while (!coords.empty()) {
            auto [coord, amount] = *prev(coords.end());
            coords.erase(prev(coords.end()));

            long long tripCount = (amount + capacity - 1) / capacity;
            res += tripCount * coord * 2;

            int freeSpace = (capacity - amount % capacity) % capacity;
            while (!coords.empty() && freeSpace) {
                int delta = min(freeSpace, prev(coords.end())->second);
                freeSpace -= delta;
                if (!(prev(coords.end())->second -= delta))
                    coords.erase(prev(coords.end()));
            }
        }
    }

    cout << res;
}