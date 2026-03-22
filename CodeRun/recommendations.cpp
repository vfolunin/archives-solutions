#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

struct Set {
    unordered_map<int, set<int>> valuesOfType;
    set<pair<int, int>> minValues;

    Set(int typeCount) {
        for (int type = 0; type <= typeCount; type++) {
            valuesOfType[type].insert(1e9);
            minValues.insert({ 1e9, type });
        }
    }

    void insert(int value, int type) {
        minValues.erase({ *valuesOfType[type].begin(), type });
        valuesOfType[type].insert(value);
        minValues.insert({ *valuesOfType[type].begin(), type });
    }

    void erase(int value, int type) {
        minValues.erase({ *valuesOfType[type].begin(), type });
        valuesOfType[type].erase(value);
        minValues.insert({ *valuesOfType[type].begin(), type });
    }

    pair<int, int> eraseMinValue(int prohibitedType) {
        auto it = minValues.begin();
        if (it->second == prohibitedType)
            it++;
        auto [value, type] = *it;
        if (it->first != 1e9)
            erase(value, type);
        return { value, type };
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int valueCount, typeCount;
    cin >> valueCount >> typeCount;

    Set values(typeCount);

    for (int value = 0; value < valueCount; value++) {
        int type;
        cin >> type;

        values.insert(value, type);
    }

    int prevType = -1;
    while (1) {
        auto [value, type] = values.eraseMinValue(prevType);
        prevType = type;
        if (value == 1e9)
            break;

        cout << value << " ";
    }
}