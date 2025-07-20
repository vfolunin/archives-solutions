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

    multiset<int> values;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        values.insert(value);
    }

    for (int i = 0; i < queryCount; i++) {
        int type, value;
        cin >> type >> value;

        auto it = values.upper_bound(value);
        if (type == 1) {
            if (it != values.end()) {
                cout << *it << "\n";
                values.erase(it);
            } else {
                cout << "-1\n";
            }
        } else {
            if (it != values.begin()) {
                cout << *--it << "\n";
                values.erase(it);
            } else {
                cout << "-1\n";
            }
        }
    }
}