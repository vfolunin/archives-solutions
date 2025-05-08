#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int aSize;
    cin >> aSize;

    unordered_set<int> a;
    for (int i = 0; i < aSize; i++) {
        int value;
        cin >> value;

        a.insert(value);
    }

    int bSize;
    cin >> bSize;

    for (int i = 0; i < bSize; i++) {
        int value;
        cin >> value;

        if (a.count(value - 1) || a.count(value + 1)) {
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";
}