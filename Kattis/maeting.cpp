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

    int aSize, bSize;
    cin >> aSize >> bSize;

    vector<int> a(aSize);
    for (int &value : a)
        cin >> value;

    unordered_set<int> b;
    for (int i = 0; i < bSize; i++) {
        int value;
        cin >> value;
        b.insert(value);
    }

    for (int value : a)
        if (b.count(value))
            cout << value << " ";
}