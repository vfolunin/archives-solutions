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

        auto ri = upper_bound(a.begin(), a.end(), value) - a.begin();
        auto li = ri - 1;

        if (li == a.size() - 1 || ri && value - a[li] < a[ri] - value)
            cout << a[li] - value << "\n";
        else
            cout << a[ri] - value << "\n";
    }
}