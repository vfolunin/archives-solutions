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

    string abbreviation;
    int nameCount;
    cin >> abbreviation >> nameCount;

    unordered_map<string, int> count;
    for (int i = 0; i < nameCount; i++) {
        string surname, name, parentName;
        cin >> surname >> name >> parentName;

        if (surname.substr(0, 1) + name[0] + parentName[0] == abbreviation)
            count[surname + " " + name + " " + parentName]++;
    }

    vector<pair<string, int>> pairs = { count.begin(), count.end() };
    sort(pairs.begin(), pairs.end(), [](auto &a, auto &b) {
        if (a.second != b.second)
            return a.second > b.second;
        return a.first < b.first;
    });

    for (auto &[name, count] : pairs)
        cout << name << " " << count << "\n";
}