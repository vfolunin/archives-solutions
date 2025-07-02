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

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    set<pair<int, int>> colorSet;
    vector<int> colors(size);
    int colorCount = 0;

    for (int i = a.size() - 1; i >= 0; i--) {
        auto it = colorSet.upper_bound({ a[i], 2e9 });
        if (it == colorSet.end()) {
            colors[i] = ++colorCount;
        } else {
            colors[i] = it->second;
            colorSet.erase(it);
        }
        colorSet.insert({ a[i], colors[i] });
    }

    cout << colorCount << "\n";
    for (int color : colors)
        cout << color << " ";
}