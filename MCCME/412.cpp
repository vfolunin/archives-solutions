#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int opCount;
    cin >> opCount;

    deque<string> windows;
    for (int i = 0; i < opCount; i++) {
        string op;
        cin >> op;

        string name;
        if (op == "Run") {
            cin.ignore();
            getline(cin, name);
        } else {
            int index = (op.size() / 4) % windows.size();
            name = windows[index];
            windows.erase(windows.begin() + index);
        }

        windows.push_front(name);
        cout << name << "\n";
    }
}