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

    int opCount;
    cin >> opCount;

    multiset<int> values;

    for (int i = 0; i < opCount; i++) {
        int op;
        cin >> op;

        if (op) {
            cout << *prev(values.end()) << "\n";
            values.erase(prev(values.end()));
        } else {
            int value;
            cin >> value;
            values.insert(value);
        }
    }
}