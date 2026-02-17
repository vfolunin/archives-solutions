#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Set {
    multiset<int> bottom, top;

    void rebalance() {
        while (bottom.size() > top.size()) {
            top.insert(*--bottom.end());
            bottom.erase(--bottom.end());
        }
        while (bottom.size() < top.size()) {
            bottom.insert(*top.begin());
            top.erase(top.begin());
        }
    }

    void insert(int x) {
        bottom.insert(x);
        rebalance();
    }

    void erase(int x) {
        if (bottom.find(x) != bottom.end())
            bottom.erase(bottom.find(x));
        else
            top.erase(top.find(x));
        rebalance();
    }

    int median() {
        return *--bottom.end();
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size, windowSize;
    cin >> size >> windowSize;

    vector<int> a(size);
    for (int &x : a)
        cin >> x;

    Set s;
    for (int i = 0; i < windowSize; i++)
        s.insert(a[i]);
    cout << s.median() << " ";

    for (int i = windowSize; i < size; i++) {
        s.erase(a[i - windowSize]);
        s.insert(a[i]);
        cout << s.median() << " ";
    }
}