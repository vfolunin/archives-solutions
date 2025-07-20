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

    vector<pair<int, int>> a(size, { -1, 0 });
    pair<int, int> common = { -1, 0 };

    for (int i = 0; i < queryCount; i++) {
        string type;
        cin >> type;

        if (type == "SET") {
            int index, value;
            cin >> index >> value;
            index--;

            a[index] = { i, value };
        } else if (type == "RESTART") {
            int value;
            cin >> value;

            common = { i, value };
        } else {
            int index;
            cin >> index;
            index--;

            cout << (a[index].first > common.first ? a[index].second : common.second) << "\n";
        }
    }
}