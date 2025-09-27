#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

class MedianFinder {
    multiset<int> l, r;

public:
    void insert(int n) {
        if (l.empty() || n <= *--l.end())
            l.insert(n);
        else
            r.insert(n);

        while (l.size() < r.size()) {
            l.insert(*r.begin());
            r.erase(r.begin());
        }
        while (r.size() + 1 < l.size()) {
            r.insert(*--l.end());
            l.erase(--l.end());
        }
    }

    int getMedian() {
        return *--l.end();
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int size;
    cin >> size;

    MedianFinder medianFinder;
    long long res = 0;

    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        medianFinder.insert(value);
        
        cout << medianFinder.getMedian() << "\n";
    }
}