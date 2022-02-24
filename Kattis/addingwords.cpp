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

    map<string, int> valueOf;
    map<int, string> nameOf;

    string op;
    while (cin >> op) {
        if (op == "def") {
            string name;
            int value;
            cin >> name >> value;

            if (valueOf.count(name))
                nameOf.erase(valueOf[name]);

            valueOf[name] = value;
            nameOf[value] = name;
        } else if (op == "calc") {
            vector<string> names, signs;
            do {
                cin >> names.emplace_back();
                cin >> signs.emplace_back();
            } while (signs.back() != "=");

            bool defined = 1;
            int value = 0;
            for (int i = 0; i < names.size(); i++) {
                if (valueOf.count(names[i]))
                    value += (i == 0 || signs[i - 1] == "+" ? 1 : -1) * valueOf[names[i]];
                else
                    defined = 0;
            }
            defined &= nameOf.count(value);

            for (int i = 0; i < names.size(); i++)
                cout << names[i] << " " << signs[i] << " ";
            cout << (defined ? nameOf[value] : "unknown") << "\n";
        } else {
            valueOf.clear();
            nameOf.clear();
        }
    }
}