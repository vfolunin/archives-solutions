#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    unordered_map<int, vector<int>> pos;
    for (int i = 1; i <= size; i++) {
        int value;
        cin >> value;
        pos[value].push_back(i);
    }

    int queryCount;
    cin >> queryCount;

    for (int i = 0; i < queryCount; i++) {
        int l, r, value;
        cin >> l >> r >> value;
        cout << (pos.count(value) && lower_bound(pos[value].begin(), pos[value].end(), l) != upper_bound(pos[value].begin(), pos[value].end(), r));
    }
}