#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct TwoSets {
    multiset<long long> l, r;
    long long rSum = 0;

    void rebalance() {
        while (l.size() < r.size()) {
            l.insert(*r.begin());
            rSum -= *r.begin();
            r.erase(r.begin());
        }
        while (r.size() + 1 < l.size()) {
            rSum += *prev(l.end());
            r.insert(*prev(l.end()));
            l.erase(prev(l.end()));
        }
    }

    void insert(long long n) {
        if (l.empty() || n <= *prev(l.end())) {
            l.insert(n);
        } else {
            rSum += n;
            r.insert(n);
        }
        rebalance();
    }

    void erase(long long n) {
        if (n <= *prev(l.end())) {
            l.erase(l.find(n));
        } else {
            rSum -= n;
            r.erase(r.find(n));
        }
        rebalance();
    }

    long long getRSum() {
        return rSum;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    vector<long long> a(size);
    for (long long &value : a)
        cin >> value;

    vector<long long> b(size);
    for (long long &value : b)
        cin >> value;

    long long aSum = 0;
    TwoSets twoSets;
    for (int i = 0; i < size; i++) {
        aSum += a[i];
        twoSets.insert(b[i] - a[i]);
    }

    int queryCount;
    cin >> queryCount;

    for (int i = 0; i < queryCount; i++) {
        int index, type, delta;
        cin >> index >> type >> delta;
        index--;

        twoSets.erase(b[index] - a[index]);
        if (type == 1) {
            a[index] += delta;
            aSum += delta;
        } else {
            b[index] += delta;
        }
        twoSets.insert(b[index] - a[index]);

        cout << aSum + twoSets.getRSum() << "\n";
    }
}