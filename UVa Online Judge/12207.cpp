#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Queue {
    list<int> collection;
    map<int, list<int>::iterator> location;

    void pushFront(int val) {
        collection.push_front(val);
        location[val] = collection.begin();
    }

    int process() {
        int val = collection.front();
        collection.pop_front();
        collection.push_back(val);
        location[val] = --collection.end();
        return val;
    }

    void erase(int val) {
        if (location.count(val)) {
            collection.erase(location[val]);
            location.erase(val);
        }
    }

    void moveToFront(int val) {
        erase(val);
        pushFront(val);
    }
};

bool solve(int test) {
    int population, opCount;
    cin >> population >> opCount;

    if (!population && !opCount)
        return 0;

    Queue q;
    for (int i = min(population, opCount); i >= 1; i--)
        q.pushFront(i);

    cout << "Case " << test << ":\n";
    for (int i = 0; i < opCount; i++) {
        char op;
        cin >> op;

        if (op == 'N') {
            cout << q.process() << "\n";
        } else {
            int val;
            cin >> val;
            q.moveToFront(val);
        }
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}