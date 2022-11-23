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

    int opCount;
    cin >> opCount;

    unordered_set<int> values;

    for (int i = 0; i < opCount; i++) {
        string op;
        cin >> op;

        if (op == "ADD") {
            int value;
            cin >> value;
            values.insert(value);
        } else if (op == "PRESENT") {
            int value;
            cin >> value;
            cout << (values.count(value) ? "YES\n" : "NO\n");
        } else {
            cout << values.size() << "\n";
        }
    }
}