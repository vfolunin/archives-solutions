#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size, queryCount;
    cin >> size >> queryCount;

    unordered_map<string, vector<string>> names;
    for (int i = 0; i < size; i++) {
        string name, surname;
        cin >> name >> surname;

        names[name.substr(0, 1) + surname.substr(0, 1)].push_back(name + " " + surname);
    }

    for (int i = 0; i < queryCount; i++) {
        string key;
        cin >> key;

        if (!names.count(key))
            cout << "nobody\n";
        else if (names[key].size() == 1)
            cout << names[key][0] << "\n";
        else
            cout << "ambiguous\n";
    }
}