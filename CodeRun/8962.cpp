#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int problemCount, selectedCount;
    cin >> problemCount >> selectedCount;

    vector<int> types(problemCount);
    for (int &type : types)
        cin >> type;

    unordered_set<int> seen;
    vector<int> uniqueTypes, repeatedTypes;

    for (int type : types) {
        if (seen.count(type)) {
            repeatedTypes.push_back(type);
        } else {
            seen.insert(type);
            uniqueTypes.push_back(type);
        }
    }

    vector<int> selected = { uniqueTypes.begin(), uniqueTypes.end() };
    selected.insert(selected.end(), repeatedTypes.begin(), repeatedTypes.end());
    selected.resize(selectedCount);

    for (int type : selected)
        cout << type << " ";
}