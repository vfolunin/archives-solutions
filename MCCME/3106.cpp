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

    int aSize;
    cin >> aSize;

    set<int> a;
    for (int i = 0; i < aSize; i++) {
        int value;
        cin >> value;
        a.insert(value);
    }

    int bSize;
    cin >> bSize;

    set<int> b;
    for (int i = 0; i < bSize; i++) {
        int value;
        cin >> value;
        b.insert(value);
    }

    for (int value : a) {
        if (auto it = b.find(value); it != b.end())
            b.erase(it);
        else
            b.insert(value);
    }

    cout << b.size() << "\n";
    for (int value : b)
        cout << value << " ";
}