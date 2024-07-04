#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    multiset<long long> lower, upper;
    long long x;

    for (int i = 1; cin >> x; i++) {
        if (lower.empty() || x <= *lower.rbegin())
            lower.insert(x);
        else
            upper.insert(x);

        while (lower.size() < upper.size()) {
            lower.insert(*upper.begin());
            upper.erase(upper.begin());
        }

        while (lower.size() > upper.size() + 1) {
            upper.insert(*--lower.end());
            lower.erase(--lower.end());
        }

        if (i % 2)
            cout << *lower.rbegin() << "\n";
        else
            cout << (*lower.rbegin() + *upper.begin()) / 2 << "\n";
    }
}