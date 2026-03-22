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

    map<string, map<string, long long>> itemCount;

    string name, item;
    int count;
    while (cin >> name >> item >> count)
        itemCount[name][item] += count;

    for (auto &[name, items] : itemCount) {
        cout << name << ":\n";
        for (auto &[item, count] : items)
            cout << item << " " << count << "\n";
    }
}