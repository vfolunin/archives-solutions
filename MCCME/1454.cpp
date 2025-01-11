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

    set<int> values;
    for (int i = 0; i < aSize; i++) {
        int value;
        cin >> value;
        values.insert(value);
    }

    int bSize;
    cin >> bSize;

    for (int i = 0; i < bSize; i++) {
        int value;
        cin >> value;
        values.insert(value);
    }

    for (int value : values)
        cout << value << " ";
}