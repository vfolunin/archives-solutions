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

    multiset<int> values;
    char type;
    int value;

    while (cin >> type >> value) {
        if (type == '+') {
            values.insert(value);
        } else if (auto it = values.find(value); it != values.end()) {
            values.erase(it);
        } else {
            cout << "ERROR";
            return 0;
        }
    }

    if (!values.empty()) {
        for (int value : values)
            cout << value << " ";
    } else {
        cout << "EMPTY\n";
    }
}