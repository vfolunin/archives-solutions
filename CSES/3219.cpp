#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

struct Counter {
    unordered_map<int, int> count;
    set<int> exValues;

    Counter() {
        for (int value = 0; value <= 2e5 + 1; value++)
            exValues.insert(value);
    }

    void add(int value, int delta) {
        if (value <= 2e5 + 1 && !count[value])
            exValues.erase(value);
        count[value] += delta;
        if (value <= 2e5 + 1 && !count[value])
            exValues.insert(value);
    }

    int getMex() {
        return *exValues.begin();
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
    cout << counter.getMex() << " ";

    for (int i = windowSize; i < size; i++) {
        counter.add(a[i - windowSize], -1);
        counter.add(a[i], 1);
        cout << counter.getMex() << " ";
    }
}