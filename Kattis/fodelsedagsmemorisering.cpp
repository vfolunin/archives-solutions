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

    int friendCount;
    cin >> friendCount;

    map<string, pair<string, int>> birthdays;
    for (int i = 0; i < friendCount; i++) {
        string name, birthday;
        int priority;
        cin >> name >> priority >> birthday;
        if (birthdays[birthday].second <= priority)
            birthdays[birthday] = { name, priority };
    }

    vector<string> names;
    for (auto &[birthday, data] : birthdays)
        names.push_back(data.first);
    sort(names.begin(), names.end());

    cout << names.size() << "\n";
    for (string &name : names)
        cout << name << "\n";
}