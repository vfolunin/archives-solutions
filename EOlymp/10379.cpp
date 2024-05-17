#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

struct FrequencyStack {
    unordered_map<int, vector<int>> pos;
    set<vector<int>> values;
    int timer = 0;

    void push(int value) {
        if (!pos[value].empty())
            values.erase({ (int)pos[value].size(), pos[value].back(), value });
        pos[value].push_back(timer++);
        values.insert({ (int)pos[value].size(), pos[value].back(), value });
    }

    int pop() {
        int value = values.rbegin()->back();
        values.erase({ (int)pos[value].size(), pos[value].back(), value });
        pos[value].pop_back();
        if (!pos[value].empty())
            values.insert({ (int)pos[value].size(), pos[value].back(), value });
        return value;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    FrequencyStack stack;

    for (string op; cin >> op; ) {
        if (op == "push") {
            int value;
            cin >> value;

            stack.push(value);
        } else {
            cout << stack.pop() << "\n";
        }
    }
}