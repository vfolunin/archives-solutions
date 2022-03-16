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

    int listCount, listSize;
    cin >> listCount >> listSize;

    map<string, int> itemCount;
    for (int i = 0; i < listCount; i++) {
        set<string> list;
        for (int j = 0; j < listSize; j++) {
            string item;
            cin >> item;
            list.insert(item);
        }
        for (const string &item : list)
            itemCount[item]++;
    }

    vector<string> commonItems;
    for (auto &[item, count] : itemCount)
        if (count == listCount)
            commonItems.push_back(item);

    cout << commonItems.size() << "\n";
    for (string &item : commonItems)
        cout << item << "\n";
}