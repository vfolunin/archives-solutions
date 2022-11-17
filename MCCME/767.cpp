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

    unordered_set<int> b;
    for (int i = 0; i < bSize; i++) {
        int value;
        cin >> value;
        b.insert(value);
    }

    cout << (a == b ? "YES" : "NO");
}