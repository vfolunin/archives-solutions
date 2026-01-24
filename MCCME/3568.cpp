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

    int queryCount;
    cin >> queryCount;

    set<int> free;
    for (int value = 1; value < 2e5; value++)
        free.insert(value);

    for (int i = 0; i < queryCount; i++) {
        int value;
        cin >> value;

        if (value > 0) {
            auto it = free.lower_bound(value);
            cout << *it << "\n";
            free.erase(it);
        } else {
            free.insert(-value);
        }
    }
}