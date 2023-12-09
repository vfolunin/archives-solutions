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

    string op;
    int value;
    unordered_set<int> values;

    while (cin >> op >> value) {
        if (op == "insert")
            values.insert(value);
        else if (op == "delete")
            values.erase(value);
        else
            cout << (values.count(value) ? "true\n" : "false\n");
    }
}