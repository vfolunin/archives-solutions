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

    int size, opCount;
    cin >> size >> opCount;

    set<vector<int>> damaged;

    for (int i = 0; i < opCount; i++) {
        vector<int> coords(3);
        for (int &coord : coords)
            cin >> coord;

        int index = find(coords.begin(), coords.end(), 0) - coords.begin();
        for (coords[index] = 1; coords[index] <= size; coords[index]++)
            damaged.insert(coords);
    }

    cout << size * size * size - damaged.size();
}