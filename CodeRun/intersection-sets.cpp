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

    set<int> a;
    int value;

    while (cin.peek() != '\n') {
        cin >> value;
        a.insert(value);
    }

    set<int> b;

    while (cin >> value)
        b.insert(value);

    for (int value : a)
        if (b.count(value))
            cout << value << " ";
}