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

    int aSize, bSize;
    cin >> aSize >> bSize;

    set<int> a;
    for (int i = 0; i < aSize; i++) {
        int value;
        cin >> value;
        a.insert(value);
    }

    set<int> b;
    for (int i = 0; i < bSize; i++) {
        int value;
        cin >> value;
        b.insert(value);
    }

    for (int value : a) {
        if (b.count(value)) {
            cout << value;
            return 0;
        }
    }

    cout << min(*a.begin(), *b.begin()) << max(*a.begin(), *b.begin());
}