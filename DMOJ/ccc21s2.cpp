#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int h, w, queryCount;
    cin >> h >> w >> queryCount;

    unordered_set<int> rows, cols;
    for (int i = 0; i < queryCount; i++) {
        char type;
        int index;
        cin >> type >> index;

        unordered_set<int> &indexes = type == 'R' ? rows : cols;
        if (indexes.count(index))
            indexes.erase(index);
        else
            indexes.insert(index);
    }

    cout << rows.size() * w + cols.size() * h - 2 * rows.size() * cols.size();
}