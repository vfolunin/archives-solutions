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

    vector<pair<string, string>> names;
    map<string, int> nameCount;

    string name, surname;
    while (cin >> name >> surname) {
        names.push_back({ surname, name });
        nameCount[name]++;
    }

    sort(names.begin(), names.end());
    for (auto &[surname, name] : names) {
        cout << name;
        if (nameCount[name] > 1)
            cout << " " << surname;
        cout << "\n";
    }
}