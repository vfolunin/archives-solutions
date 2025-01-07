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
    vector<int> stack;

    for (int i = 0; i < opCount; i++) {
        int type;
        cin >> type;

        if (type == 1) {
            int value;
            cin >> value;

            values.insert(value);
            stack.push_back(value);
        } else if (type == 2) {
            values.erase(values.find(stack.back()));
            stack.pop_back();
        } else {
            cout << *values.begin() << "\n";
        }
    }
}