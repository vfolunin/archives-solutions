#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

struct Counter {
    unordered_map<int, int> count;
    multiset<int> counts;

    void add(int value, int delta) {
        if (count.count(value))
            counts.erase(counts.find(count[value]));
        count[value] += delta;
        counts.insert(count[value]);
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    Counter counter;
    int res = 0;

    for (int l = 0, r = 0; r < size; r++) {
        counter.add(a[r], 1);

        while (*counter.counts.rbegin() > 1)
            counter.add(a[l++], -1);

        res = max(res, r - l + 1);
    }

    cout << res;
}