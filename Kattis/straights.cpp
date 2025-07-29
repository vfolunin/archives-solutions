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

    int size;
    cin >> size;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    sort(a.begin(), a.end());

    unordered_multiset<int> values;
    for (int value : a) {
        if (auto it = values.find(value - 1); it != values.end())
            values.erase(it);
        values.insert(value);
    }

    cout << values.size();
}