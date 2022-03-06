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

    map<string, int> vars;

    string command;
    while (cin >> command) {
        if (command == "define") {
            int value;
            string name;
            cin >> value >> name;

            vars[name] = value;
        } else {
            string nameA, op, nameB;
            cin >> nameA >> op >> nameB;

            if (!vars.count(nameA) || !vars.count(nameB))
                cout << "undefined\n";
            else if (op == "<" && vars[nameA] < vars[nameB] ||
                     op == "=" && vars[nameA] == vars[nameB] ||
                     op == ">" && vars[nameA] > vars[nameB])
                cout << "true\n";
            else
                cout << "false\n";
        }
    }
}