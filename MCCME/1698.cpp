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
        if (count[value])
            counts.erase(counts.find(count[value]));
        count[value] += delta;
        if (count[value] > 0)
            counts.insert(count[value]);
        else
            count.erase(value);
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int opCount;
    cin >> opCount;

    Counter counter;

    for (int i = 0; i < opCount; i++) {
        string op;
        int value;
        cin >> op >> value;

        counter.add(value, op == "insert" ? 1 : -1);

        if (counter.count.size() > 1 && *counter.counts.rbegin() > 1)
            cout << "both\n";
        else if (!counter.counts.empty() && *counter.counts.rbegin() > 1)
            cout << "homo\n";
        else if (counter.count.size() > 1)
            cout << "hetero\n";
        else
            cout << "neither\n";
    }
}