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

    map<int, vector<int>> indexes;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        indexes[value].push_back(i);
    }

    for (auto &[value, indexes] : indexes) {
        if (indexes.size() == 1) {
            cout << indexes[0] + 1;
            return 0;
        }
    }

    cout << 0;
}