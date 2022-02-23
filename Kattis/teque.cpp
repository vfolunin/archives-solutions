#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Teque {
    deque<int> l, r;

    void rebalance() {
        while (l.size() <= r.size()) {
            l.push_back(r.front());
            r.pop_front();
        }
        while (l.size() > r.size() + 1) {
            r.push_front(l.back());
            l.pop_back();
        }
    }

    void pushFront(int value) {
        l.push_front(value);
        rebalance();
    }

    void pushMiddle(int value) {
        r.push_front(value);
        rebalance();
    }

    void pushBack(int value) {
        r.push_back(value);
        rebalance();
    }

    int operator[](int i) {
        return i < l.size() ? l[i] : r[i - l.size()];
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int opCount;
    cin >> opCount;

    Teque teque;

    for (int i = 0; i < opCount; i++) {
        string op;
        int arg;
        cin >> op >> arg;

        if (op == "push_front")
            teque.pushFront(arg);
        else if (op == "push_middle")
            teque.pushMiddle(arg);
        else if (op == "push_back")
            teque.pushBack(arg);
        else
            cout << teque[arg] << "\n";
    }
}