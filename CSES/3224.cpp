#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

struct Counter {
    unordered_map<int, int> count;
    set<pair<int, int>> counts;

    void add(int value, int delta) {
        counts.erase({ count[value], -value });
        count[value] += delta;
        counts.insert({ count[value], -value });
    }

    int getMode() {
        return -counts.rbegin()->second;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size, windowSize;
    cin >> size >> windowSize;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    Counter counter;
    for (int i = 0; i < windowSize; i++)
        counter.add(a[i], 1);
    cout << counter.getMode() << " ";

    for (int i = windowSize; i < size; i++) {
        counter.add(a[i - windowSize], -1);
        counter.add(a[i], 1);
        cout << counter.getMode() << " ";
    }
}