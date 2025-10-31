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

    vector<int> count(1001);
    int maxCount = 0;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        maxCount = max(maxCount, ++count[value]);
    }

    map<int, set<int>> groups;
    for (int value = 0; value < count.size(); value++)
        if (count[value])
            groups[count[value]].insert(value);

    set<int> &a = groups.rbegin()->second, &b = next(groups.rbegin())->second;
    if (groups.rbegin()->second.size() > 1)
        cout << *a.rbegin() - *a.begin();
    else
        cout << max(abs(*a.rbegin() - *b.rbegin()), abs(*a.rbegin() - *b.begin()));
}