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
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        pos[value].push_back(i);
    }

    vector<int> res;
    for (int l = 0, r = size - 1; l < size; l++, r--) {
        if (pos[abs(l - r)].empty()) {
            cout << -1;
            return 0;
        }
        res.push_back(pos[abs(l - r)].back());
        pos[abs(l - r)].pop_back();
    }

    for (int index : res)
        cout << index + 1 << " ";
}