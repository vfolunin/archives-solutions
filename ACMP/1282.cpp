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

    int studentCount;
    cin >> studentCount;

    map<string, int> nameCount;
    int maxNameCount = 0;
    vector<string> names;

    for (int i = 0; i < studentCount; i++) {
        string surname, name, gender;
        cin >> surname >> name >> gender;

        if (gender != "m" && gender != "w")
            cin >> gender;

        if (gender == "w") {
            maxNameCount = max(maxNameCount, ++nameCount[name]);
            if (nameCount[name] == 1)
                names.push_back(name);
        }
    }

    if (maxNameCount == 0) {
        cout << "NO DATA!";
    } else if (maxNameCount == 1) {
        cout << "UNIQUE!";
    } else {
        bool first = 1;
        for (string &name : names) {
            if (nameCount[name] == maxNameCount) {
                if (first)
                    first = 0;
                else
                    cout << ",";
                cout << name;
            }
        }
    }
}