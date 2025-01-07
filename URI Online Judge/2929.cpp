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

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int opCount;
    cin >> opCount;

    multiset<int> values;
    vector<int> stack;

    for (int i = 0; i < opCount; i++) {
        string type;
        cin >> type;

        if (type == "PUSH") {
            int value;
            cin >> value;

            values.insert(value);
            stack.push_back(value);
        } else if (type == "POP") {
            if (stack.empty()) {
                cout << "EMPTY\n";
            } else {
                values.erase(values.find(stack.back()));
                stack.pop_back();
            }
        } else {
            if (stack.empty()) {
                cout << "EMPTY\n";
            } else {
                cout << *values.begin() << "\n";
            }
        }
    }
}