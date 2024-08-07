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
        if (count[value])
            counts.insert({ count[value], -value });
    }

    int get() {
        if (counts.empty())
            return 0;
        return -prev(counts.end())->second;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int queryCount;
    cin >> queryCount;

    Counter counter;
    for (int i = 0; i < queryCount; i++) {
        char type;
        int value;
        cin >> type >> value;

        counter.add(value, type == '+' ? 1 : -1);

        cout << counter.get() << "\n";
    }
}