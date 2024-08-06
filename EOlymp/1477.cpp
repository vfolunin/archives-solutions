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

    set<pair<double, int>> values;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        values.insert({ value, i });
    }

    for (int i = size; values.size() > 1; i++) {
        auto [aValue, aIndex] = *values.begin();
        values.erase(values.begin());
        auto [bValue, bIndex] = *values.begin();
        values.erase(values.begin());

        values.insert({ (aValue + bValue) / 2, i });

        cout << aIndex + 1 << " " << bIndex + 1 << "\n";
    }
}