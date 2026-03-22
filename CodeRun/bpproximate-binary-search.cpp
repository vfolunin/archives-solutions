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

    int size, queryCount;
    cin >> size >> queryCount;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    for (int i = 0; i < queryCount; i++) {
        int value;
        cin >> value;

        auto r = lower_bound(a.begin(), a.end(), value);
        if (r == a.begin()) {
            cout << *r << "\n";
            continue;
        }

        auto l = prev(r);
        cout << (r == a.end() || value - *l <= *r - value ? *l : *r) << "\n";
    }
}