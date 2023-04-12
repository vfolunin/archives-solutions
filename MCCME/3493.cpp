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

    for (string op; cin >> op; ) {
        if (op == "CLEAR") {
            values.clear(); 
        } else if (op == "ADD") {
            int value;
            cin >> value;
            values.insert(value);
        } else {
            if (!values.empty()) {
                cout << *values.begin() << "\n";
                values.erase(values.begin());
            } else {
                cout << "CANNOT\n";
            }
        }
    }
}