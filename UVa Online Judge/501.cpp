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

void solve(int test) {
    int addCount, getCount;
    cin >> addCount >> getCount;

    vector<int> add(addCount);
    for (int &x : add)
        cin >> x;

    vector<int> get(getCount);
    for (int &x : get)
        cin >> x;

    Set s;

    if (test)
        cout << "\n";
    for (int addI = 0, getI = 0; getI < getCount; getI++) {
        for (; addI < get[getI]; addI++)
            s.add(add[addI]);
        cout << s.get() << "\n";
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve(i);
}