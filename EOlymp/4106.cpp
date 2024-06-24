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

    vector<vector<int>> subsets;
    for (int mask = 1; mask < (1 << size); mask++) {
        subsets.emplace_back();
        for (int bit = 0; bit < size; bit++)
            if (mask & (1 << bit))
                subsets.back().push_back(bit);
    }

    sort(subsets.begin(), subsets.end(), [](auto &a, auto &b) {
        if (a.size() != b.size())
            return a.size() < b.size();
        return a < b;
    });

    for (vector<int> &subset : subsets) {
        for (int value : subset)
            cout << value + 1;
        cout << "\n";
    }
}