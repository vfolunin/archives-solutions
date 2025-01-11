#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Set {
    multiset<int> l, r;
    int lSize = 0;

    void rebalance() {
        while (l.size() < lSize) {
            l.insert(*r.begin());
            r.erase(r.begin());
        }
        while (l.size() > lSize) {
            r.insert(*--l.end());
            l.erase(--l.end());
        }
    }

    void add(int x) {
        l.insert(x);
        rebalance();
    }

    int get() {
        lSize++;
        rebalance();
        return *--l.end();
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
    int addCount, getCount;
    cin >> addCount >> getCount;

    vector<int> add(addCount);
    for (int &value : add)
        cin >> value;

    vector<int> get(getCount);
    for (int &value : get)
        cin >> value;

    Set values;

    for (int addI = 0, getI = 0; getI < getCount; getI++) {
        for (; addI < get[getI]; addI++)
            values.add(add[addI]);
        cout << values.get() << "\n";
    }
}