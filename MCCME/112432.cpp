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

    int size;
    cin >> size;
    cin.get();

    unordered_map<string, int> count;
    for (int i = 0; i < size; i++) {
        string name;
        getline(cin, name);
        count[name]++;
    }

    vector<pair<string, int>> pairs(count.begin(), count.end());
    sort(pairs.begin(), pairs.end(), [](auto &a, auto &b) {
        if (a.second != b.second)
            return a.second > b.second;
        return a.first < b.first;
    });

    for (auto &[name, count] : pairs)
        cout << name << "\n";
}