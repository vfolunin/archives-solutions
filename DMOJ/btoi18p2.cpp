#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

struct Counter {
    unordered_map<int, int> count;
    unordered_map<int, int> threshold;
    int thresholdPassed = 0;

    void add(int value, int delta) {
        if (!threshold.count(value))
            return;
        thresholdPassed -= count[value] >= threshold[value];
        count[value] += delta;
        thresholdPassed += count[value] >= threshold[value];
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size, maxValue, thresholdCount;
    cin >> size >> maxValue >> thresholdCount;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    Counter counter;
    for (int i = 0; i < thresholdCount; i++) {
        int value;
        cin >> value >> counter.threshold[value];
    }

    int res = 1e9;
    for (int l = 0, r = 0; l < a.size(); l++) {
        while (r < a.size() && counter.thresholdPassed < counter.threshold.size())
            counter.add(a[r++], 1);

        if (counter.thresholdPassed == counter.threshold.size())
            res = min(res, r - l);

        counter.add(a[l], -1);
    }

    if (res != 1e9)
        cout << res << "\n";
    else
        cout << "impossible\n";
}