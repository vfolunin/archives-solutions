#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct SetWithMiddle {
    multiset<int> lower, upper;

    void rebalance() {
        while (lower.size() + 1 < upper.size()) {
            lower.insert(*upper.begin());
            upper.erase(upper.begin());
        }
        while (lower.size() > upper.size()) {
            upper.insert(*--lower.end());
            lower.erase(--lower.end());
        }
    }

    void push(int value) {
        if (!upper.empty() && value < *upper.begin())
            lower.insert(value);
        else
            upper.insert(value);
        rebalance();
    }

    int pop() {
        int value = *upper.begin();
        upper.erase(upper.begin());
        rebalance();
        return value;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    SetWithMiddle setWithMiddle;

    string query;
    while (cin >> query) {
        if (isdigit(query[0]))
            setWithMiddle.push(stoi(query));
        else
            cout << setWithMiddle.pop() << "\n";
    }
}