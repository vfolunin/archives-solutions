#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    multiset<int> values;
    while (1) {
        int value;
        if (!(cin >> value))
            return 0;

        values.insert(value);

        if (cin.peek() != ' ')
            break;
    }

    while (!values.empty()) {
        int value = *prev(values.end());
        values.erase(prev(values.end()));

        if (values.size() < value) {
            cout << "fail\n";
            return 1;
        }

        vector<int> nextValues;
        for (int i = 0; i < value; i++) {
            nextValues.push_back(*prev(values.end()) - 1);
            values.erase(prev(values.end()));
        }

        values.insert(nextValues.begin(), nextValues.end());
    }

    cout << "ok\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}