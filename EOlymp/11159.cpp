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

    int size, queryCount;
    cin >> size >> queryCount;

    vector<vector<int>> pos(3);
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        pos[value - 1].push_back(i);
    }

    for (int i = 0; i < queryCount; i++) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;

        for (vector<int> &p : pos)
            cout << upper_bound(p.begin(), p.end(), r) - lower_bound(p.begin(), p.end(), l) << " ";
        cout << "\n";
    }
}