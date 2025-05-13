#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct TwoSets {
    multiset<int> l, r;

    void rebalance() {
        while (l.size() < r.size()) {
            l.insert(*r.begin());
            r.erase(r.begin());
        }
        while (r.size() + 1 < l.size()) {
            r.insert(*prev(l.end()));
            l.erase(prev(l.end()));
        }
    }

    void insert(int n) {
        if (l.empty() || n <= *prev(l.end()))
            l.insert(n);
        else
            r.insert(n);
        rebalance();
    }

    void erase(int n) {
        if (n <= *prev(l.end()))
            l.erase(l.find(n));
        else
            r.erase(r.find(n));
        rebalance();
    }

    int getMedian() {
        return *prev(l.end());
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    TwoSets twoSets;
    long long res = 0;

    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        twoSets.insert(value);
        res += twoSets.getMedian();
    }

    cout << res;
}