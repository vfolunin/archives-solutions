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

    set<string> in;
    for (int i = 0; i < opCount; i++) {
        string op, name;
        cin >> op >> name;

        if (op == "entry") {
            cout << name << " entered";
            if (in.count(name))
                cout << " (ANOMALY)";
            cout << "\n";
            in.insert(name);
        } else {
            cout << name << " exited";
            if (!in.count(name))
                cout << " (ANOMALY)";
            cout << "\n";
            in.erase(name);
        }
    }
}