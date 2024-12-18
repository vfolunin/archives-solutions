#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <string>
using namespace std;

struct QueueWithMiddle {
    deque<int> l, r;

    void rebalance() {
        while (l.size() < r.size()) {
            l.push_back(r.front());
            r.pop_front();
        }
        while (l.size() > r.size() + 1) {
            r.push_front(r.back());
            r.pop_back();
        }
    }

    void pushBack(int value) {
        r.push_back(value);
        rebalance();
    }

    void pushMiddle(int value) {
        r.push_front(value);
        rebalance();
    }

    int pop() {
        int res = l.front();
        l.pop_front();
        rebalance();
        return res;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int opCount;
    cin >> opCount;

    QueueWithMiddle q;

    for (int i = 0; i < opCount; i++) {
        char op;
        cin >> op;

        if (op == '+') {
            int value;
            cin >> value;
            q.pushBack(value);
        } else if (op == '*') {
            int value;
            cin >> value;
            q.pushMiddle(value);
        } else {
            cout << q.pop() << "\n";
        }
    }
}