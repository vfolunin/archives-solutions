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

    int size;
    cin >> size;

    int maxGoals = 0;
    vector<string> names;

    for (int i = 0; i < size; i++) {
        string surname, name;
        int goals;
        cin >> surname >> name >> goals >> goals;

        if (maxGoals < goals) {
            maxGoals = goals;
            names = { surname + " " + name };
        } else if (maxGoals == goals) {
            names.push_back(surname + " " + name);
        }
    }

    for (string &name : names)
        cout << name << "\n";
    cout << maxGoals;
}