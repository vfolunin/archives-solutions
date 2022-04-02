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

    int day = 1;
    map<string, int> enter, exit;
    string command;

    while (cin >> command) {
        if (command == "ENTER") {
            string name;
            int time;
            cin >> name >> time;
            enter[name] = time;
        } else if (command == "EXIT") {
            string name;
            int time;
            cin >> name >> time;
            exit[name] += time - enter[name];
        } else if (command == "CLOSE") {
            if (day > 1)
                cout << "\n";
            cout << "Day " << day++ << "\n";
            cout.precision(2);
            for (auto &[name, cost] : exit)
                cout << name << " $" << fixed << cost / 10.0 << "\n";
            enter.clear();
            exit.clear();
        }
    }
}